//
// Created by guy cohen on 04/06/2022.
//

#include "JobQueue.h"
#include "stdlib.h"
#include "segel2.h"


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
/*
JobEntry& JobEntry::operator=(JobEntry& job) {
    if(this == &job){
        return *this;
    }
    this->connfd = job.connfd;
    this->arrival_time = job.arrival_time;
    this->dispatch_time = job.dispatch_time;
    return *this;
}*/

bool operator==(const JobEntry &job1, const JobEntry& job2){
    if(job1.arrival_time.tv_usec == job2.arrival_time.tv_usec){
        return true;
    }
    return false;
}



JobQueue::JobQueue(){
    if (pthread_mutex_init(&mutex, nullptr) != 0){
        //assert(false);
        unix_error("mutex init");
    }
    if (pthread_cond_init(&cond_write, nullptr) != 0){
        //assert(false);
        unix_error("cond init");
    }
    
}

JobQueue::~JobQueue(){
    //assert(array != nullptr);
    free(array);
}
void JobQueue::Initialize(int maxSize){
    array = (JobEntry*)malloc(sizeof(JobEntry) * maxSize);
    if (array == nullptr){
        exit(0);
    }
    size = 0;
    max_size = maxSize;
    
    front = -1;
    rear = -1;
    
    for (int idx = 0; idx < max_size; idx++) {
        array[idx] = JobEntry::NO_FD;
    }
    
}
bool JobQueue::isEmpty() const{
    if (front == -1)
        return true;
    else
        return false;
}
bool JobQueue::isFull() const{
    if ((front == rear + 1) || (front == 0 && rear == max_size - 1)) {
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
    if (isFull()) {
       result = false;
    }
    else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % max_size;
        array[rear] = job;
    }
    size++;
    writers--;
    pthread_cond_signal(&cond_write);
    pthread_mutex_unlock(&mutex);
}

void JobQueue::pop(JobEntry &job, int index){
    pthread_mutex_lock(&mutex);
    //assert(!isEmpty());
    while (writers > 0 || isEmpty()){
        pthread_cond_wait(&cond_write, &mutex);
        //assert(!isEmpty());
    }
    writers++;
    
    //assert(!isEmpty());
    //int index = find(job);
    //assert(index >= 0 && index < size);
    JobEntry element = array[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    }
        // Q has only one element,
        // so we reset the queue after deleting it.
    else {
        front = (front + 1) % max_size;
    }
    job = (element);
    
    size--;
    /*
    cout << "================== JobQueue::Pop["<<size<<"] ==================" << endl;
    for (int i = 0; i < size; i++) {
        cout << "JobQueue::job["<<i<<"]:: fd=" << array[i].connfd << endl;
    }
    cout << "======================================================" << endl;
    */
    writers--;
    pthread_cond_signal(&cond_write);
    pthread_mutex_unlock(&mutex);
}


int JobQueue::find(JobEntry &job) const{
    for(int i = 0; i < this->size; i++){
        if(this->array[i] == job){
            return i;
        }
    }
    return NotFound;
}