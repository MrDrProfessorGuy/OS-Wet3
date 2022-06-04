//
// Created by guy cohen on 04/06/2022.
//

#include "JobQueue.h"
#include "assert.h"

JobEntry::JobEntry(int connfd): connfd(connfd) {
    setTime(Arrival);
}
JobEntry::~JobEntry() {

}

void JobEntry::setTime(JobEntry::Time timeField) {
    if (timeField == Time::Arrival){
        gettimeofday(&arrival_time, nullptr);
    }
    else if (timeField == Time::Dispatch){
        gettimeofday(&dispatch_time, nullptr);
    }
}

JobEntry::JobEntry(JobEntry &job) {
    connfd = job.connfd;
    arrival_time = job.arrival_time;
    dispatch_time = job.dispatch_time;
}

JobEntry& JobEntry::operator=(JobEntry& job) {
    if(this == &job){
        return *this;
    }
    this->connfd = job.connfd;
    this->arrival_time = job.arrival_time;
    this->dispatch_time = job.dispatch_time;
    return *this;
}

bool operator==(const JobEntry &job1, const JobEntry& job2){
    if(job1.arrival_time.tv_usec == job2.arrival_time.tv_usec){
        return true;
    }
    return false;
}



JobQueue::JobQueue(unsigned int maxSize){
    if (pthread_mutex_init(&mutex, nullptr) != 0){
        assert(false);
    }
    if (pthread_cond_init(&cond_write, nullptr) != 0){
        assert(false);
    }
    
    array = (JobEntry*)malloc(sizeof(JobEntry) * maxSize);
    if (array == nullptr){
        exit(0);
    }
    size = 0;
    max_size = maxSize;
    
}
JobQueue::~JobQueue(){
    assert(array != nullptr);
    free(array);
}

bool JobQueue::isEmpty(){
    if (size == 0){
        return true;
    }
    return false;
}
bool JobQueue::isFull(){
    if (size == max_size){
        return true;
    }
    return false;
}

void JobQueue::insert(JobEntry &job, bool &result){
    pthread_mutex_lock(&mutex);
    while(writers > 0){
        pthread_cond_wait(&cond_write, &mutex);
    }
    writers++;
    
    //assert(find(job) == NotFound);
    result = true;
    if (isFull()){
        result = false;
    }
    else{
        array[size].operator=(job);
        size++;
    }
    
    writers--;
    pthread_cond_signal(&cond_write);
    pthread_mutex_unlock(&mutex);
}

void JobQueue::pop(JobEntry &job){
    pthread_mutex_lock(&mutex);
    assert(!isEmpty());
    while (writers > 0 || isEmpty()){
        pthread_cond_wait(&cond_write, &mutex);
        assert(!isEmpty());
    }
    writers++;
    
    assert(!isEmpty());
    //int index = find(job);
    //assert(index > NotFound);
    job = array[0];
    for (int idx = 0; idx < max_size-1; idx++) {
        array[idx].operator=(array[idx + 1]);
    }
    size--;
    
    writers--;
    pthread_cond_signal(&cond_write);
    pthread_mutex_unlock(&mutex);
}

int JobQueue::find(JobEntry &job){
    for(int i = 0; i < this->size; i++){
        if(this->array[i] == job){
            return i;
        }
    }
    return NotFound;
}