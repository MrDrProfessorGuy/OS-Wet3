
#include "QueueManager.h"
#include "segel2.h"



/*
QueueManager::QueueManager(int max_size, PolicyType policy) : handlers(0), master_waiting(0), max_size(max_size), size(0),
                                                thread_queue(max_size), jobs_queue(max_size), policy(policy){
    if (pthread_mutex_init(&mutex, nullptr) != 0){
        assert(false);
    }
    if (pthread_cond_init(&cond_write, nullptr) != 0){
        assert(false);
    }
    if (pthread_cond_init(&cond_master, nullptr) != 0){
        assert(false);
    }
    
}*/
QueueManager::QueueManager() : handlers(0), master_waiting(0), max_size(0), size(0),
                                thread_queue(), jobs_queue(), policy(Block){
    if (pthread_mutex_init(&mutex, nullptr) != 0){
        //assert(false);
        unix_error("mutex_error");
    }
    if (pthread_cond_init(&cond_write, nullptr) != 0){
        //assert(false);
        unix_error("cond error");
    }
    if (pthread_cond_init(&cond_master, nullptr) != 0){
        //assert(false);
        unix_error("cond error");
    }
    //cout << "QueueManager:: Initialized"<< endl;
}

QueueManager::~QueueManager() {}


QueueManager& QueueManager::getInstance() // make SmallShell singleton
{
    static QueueManager instance; // Guaranteed to be destroyed.
    // Instantiated on first use.
    return instance;
}


bool QueueManager::policyHandler(JobEntry& job) {
    //cout << "Master::createJob()::PolicyHandler::start fd="<<job.connfd << endl;
    if(policy == Block){
        master_waiting++;
        handlers--;
            //cout << "Master::createJob()::PolicyHandler::going to sleep fd="<<job.connfd << endl;
        while(isFull()){
            pthread_cond_wait(&cond_master, &mutex);
        }
        //cout << "Master::createJob()::PolicyHandler::waking up fd="<<job.connfd << endl;
        handlers++;
        master_waiting--;
        return true;
    }
    else if(policy == DropTail){
        Close(job.connfd);
        //cout << "Policy::DropTail:: fd="<<job.connfd << endl;
        return false;
    }
    else if(policy == DropHead){
        JobEntry oldest(JobEntry::NO_FD);
        if (!jobs_queue.isEmpty()){
            jobs_queue.pop(oldest);
            //cout << "Policy::DropHead:: fd="<<oldest.connfd << endl;
            Close(oldest.connfd);
            size--;
            return true;
        }
        else{
            //cout << "Policy::DropHead::Empty fd="<<job.connfd << endl;
            Close(job.connfd);
            return false;
        }
    }
    else{
        int del_num = ceil(0.3*jobs_queue.size);
        //cout << "Policy::Random:: del_num="<<del_num << endl;
        JobEntry deleted_job(JobEntry::NO_FD);
        for(int i = 0; i < del_num; i++){
            if (jobs_queue.isEmpty()){
                break;
            }
            int delete_idx = rand()%jobs_queue.size;
            jobs_queue.pop(deleted_job,delete_idx);
            //cout << "Policy::Random:: fd="<<deleted_job.connfd << endl;
            Close(deleted_job.connfd);
            size--;
        }
        if (isFull()){
            close(job.connfd);
            return false;
        }
        return true;
    }
}

void QueueManager::createJob(JobEntry job){
    //cout << "createJob["<<size<<"]::start fd=" << job.connfd << endl;
    job.setTime(JobEntry::Arrival);
    pthread_mutex_lock(&mutex);
    //master_waiting++;
    while (handlers > 0){
        pthread_cond_wait(&cond_write, &mutex);
    }
    //master_waiting--;
    handlers++;
    
    bool create = true;
    if (isFull()){
        //cout << "createJob::QueueFull fd=" << job.connfd << endl;
        create = policyHandler(job);
    }
    
    if (create){
        //cout << "createJob::insert fd=" << job.connfd << endl;
        bool result = false;
        jobs_queue.insert(job, result);
        if(result){
            size++;
        }
    }
    //cout << "Master::createJob()::Done fd="<<job.connfd << endl;
    
    handlers--;
    pthread_cond_signal(&cond_write);
    pthread_mutex_unlock(&mutex);
}

void QueueManager::getRequest(JobEntry &job){
    pthread_mutex_lock(&mutex);
    while (handlers > 0 || jobs_queue.isEmpty()){
        pthread_cond_wait(&cond_write, &mutex);
    }
    handlers++;
    
    //cout << "Thread(" << pthread_self() << ")::getRequest():: { " <<endl;
    //cout << "fd="<<job.connfd <<endl;
    //cout << "handlers="<<handlers << endl;
    //cout << "size=" << size << endl;
    
    bool result = false;
    
    jobs_queue.pop(job);
    job.setTime(JobEntry::Dispatch);
    //thread_queue_size++;
    thread_queue.insert(result);
    //assert(result);
    
    handlers--;
    if (master_waiting > 0 && !isFull()){
        pthread_cond_signal(&cond_master);
    }
    else{
        pthread_cond_signal(&cond_write);
    }
    pthread_mutex_unlock(&mutex);
}

void QueueManager::finishRequest(JobEntry &job){
    pthread_mutex_lock(&mutex);
    //assert(!thread_queue.isEmpty());
    while (handlers > 0){
        pthread_cond_wait(&cond_write, &mutex);
    }
    handlers++;
    
    //cout << "Thread(" << pthread_self() << ")::finishRequest():: fd="<<job.connfd << endl;
    thread_queue.remove();
    //thread_queue_size--;
    Close(job.connfd);
    job.connfd = JobEntry::NO_FD;
    size--;
    
    
    handlers--;
    if (master_waiting > 0){
        pthread_cond_signal(&cond_master);
    }
    else{
        pthread_cond_signal(&cond_write);
    }
    pthread_mutex_unlock(&mutex);
}



bool QueueManager::isFull(){
    return (this->size == this->max_size);
}

bool QueueManager::isEmpty() {
    return (this->size == 0);
}

int QueueManager::maxSize(){
    return this->max_size;
}
int QueueManager::Size(){
    return this->size;
}

void QueueManager::increaseSize(){
    this->size++;
}
void QueueManager::decreaseSize(){
    this->size--;
}
bool QueueManager::contains(JobEntry job) {
    
    return true;
}










