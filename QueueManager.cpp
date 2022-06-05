
#include "QueueManager.h"
#include "segel.h"
#include "math.h"
#include "assert.h"



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
    
}

QueueManager::~QueueManager() {}

 QueueManager& QueueManager::getInstance() // make SmallShell singleton
{
    static QueueManager abc; // Guaranteed to be destroyed.
    // Instantiated on first use.
    return abc;
}


QueueManager& QueueManager::AuxGetInstance(int max_size, PolicyType policy) {
     static QueueManager asd(max_size, policy); // Guaranteed to be destroyed.
    // Instantiated on first use.
    return asd;
}


bool QueueManager::policyHandler(JobEntry& job) {
    
    if(policy == Block){
        while(isFull()){
            pthread_cond_wait(&cond_write, &mutex);
        }
        return true;
    }
    else if(policy == DropTail){
        Close(job.connfd);
        return false;
    }
    else if(policy == DropHead){
        JobEntry oldest(JobEntry::NO_FD);
        jobs_queue.pop(oldest);
        Close(oldest.connfd);
        return true;
    }
    else{
        int del_num = roundf(0.7*jobs_queue.size + 0.5);
        JobEntry deleted_job(JobEntry::NO_FD);
        for(int i = 0; i < del_num; i++){
            int delete_idx = rand()%jobs_queue.size;
            jobs_queue.pop(deleted_job,delete_idx);
            Close(deleted_job.connfd);
        }
        return true;
    }
}
void QueueManager::createJob(JobEntry job){
    pthread_mutex_lock(&mutex);
    master_waiting++;
    while (handlers > 0){
        pthread_cond_wait(&cond_master, &mutex);
    }
    master_waiting--;
    handlers++;
    
    bool create = true;
    if (isFull()){
        create = policyHandler(job);
    }
    
    if (create){
        bool result = false;
        jobs_queue.insert(job, result);
        if(result){
            size++;
        }
    }
    
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
    
    bool result = false;
    jobs_queue.pop(job);
    thread_queue.insert(result);
    assert(result);
    
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
    assert(!thread_queue.isEmpty());
    while (handlers > 0){
        pthread_cond_wait(&cond_write, &mutex);
    }
    handlers++;
    
    
    thread_queue.remove();
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
    
    //return mapContains(this->list,(MapKeyElement) &job.arrival_time.tv_usec);
    return true;
}










