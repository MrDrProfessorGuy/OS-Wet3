
#include "QueueManager.h"


void QueueManager::createJob(JobEntry job){
    pthread_mutex_lock(&mutex);
    while (writers > 0){
        pthread_cond_wait(&cond_write, &mutex);
    }
    writers++;
    
    if (isFull()){
        policy();
    }
    
    bool result = false;
    jobs_queue.insert(job, result);
    if(result){
        size++;
    }
    
    writers--;
    pthread_cond_signal(&cond_write);
    pthread_mutex_unlock(&mutex);
}

void QueueManager::getRequest(JobEntry &job){
    pthread_mutex_lock(&mutex);
    //assert(!isEmpty());
    while (writers > 0 || isEmpty()){
        pthread_cond_wait(&cond_write, &mutex);
        //assert(!isEmpty());
    }
    writers++;
    
    bool result = false;
    
    jobs_queue.pop(job);
    thread_queue.insert(result);
    assert(result);
    
    writers--;
    pthread_cond_signal(&cond_write);
    pthread_mutex_unlock(&mutex);
}

bool QueueManager::isFull(){
    return (this->size == this->max_size);
}

bool QueueManager::isEmpty() {
    return (this->size == 0);
}

unsigned int QueueManager::maxSize(){
    return this->max_size;
}
unsigned int QueueManager::Size(){
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










