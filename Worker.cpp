//
// Created by guy cohen on 05/06/2022.
//

#include "Worker.h"
#include "QueueManager.h"
#include "request2.h"



Worker::Worker() : current_job(JobEntry::NO_FD) {}
Worker::~Worker() {}

void Worker::start() {
    QueueManager& manager = QueueManager::getInstance();
    
    while (true){
        manager.getRequest(current_job);
        //assert(current_job.connfd != JobEntry::NO_FD);
        current_job.setTime(JobEntry::Dispatch);
    
        //requestHandle(current_job.connfd);
        manager.finishRequest(current_job);
        
    }
}


void* startButInShittyCode(void* worker_arg) {
    BadWorker* worker = (BadWorker*) worker_arg;
    worker->thread = pthread_self();
    QueueManager& manager = QueueManager::getInstance();
    
    //cout << "Thread(" << worker->thread_id << "):: Started" << endl;
    
    while (true){
        manager.getRequest(worker->current_job);
        worker->total_count++;
        //assert(worker->current_job.connfd != JobEntry::NO_FD);
        //cout << "Thread(" << worker->thread_id << "=========BeforeSetTime=========" << endl;
        worker->current_job.setTime(JobEntry::Dispatch);
        //cout << "Thread(" << worker->thread_id << "=========BeforeRequestHandle=========" << endl;
    
        requestHandle(worker->current_job.connfd, *worker);
        manager.finishRequest(worker->current_job);
    }
}
void BadWorkerInit(BadWorker& worker, int thread_id){
    JobEntry job(JobEntry::NO_FD);
    worker.current_job = (job);
    worker.thread_id = thread_id;
    worker.dynamic_count = 0;
    worker.static_count = 0;
    worker.total_count = 0;
    
    //worker.thread = thread;
}


