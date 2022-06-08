//
// Created by guy cohen on 05/06/2022.
//

#include "Worker.h"
#include "QueueManager.h"
#include "request2.h"

#include "assert.h"
#include "iostream"
using namespace std;

Worker::Worker() : current_job(JobEntry::NO_FD) {}
Worker::~Worker() {}

void Worker::start() {
    QueueManager& manager = QueueManager::getInstance();
    
    while (true){
        manager.getRequest(current_job);
        assert(current_job.connfd != JobEntry::NO_FD);
        current_job.setTime(JobEntry::Dispatch);
    
        requestHandle(current_job.connfd);
        manager.finishRequest(current_job);
        
    }
}


void* startButInShittyCode(void* worker_arg) {
    BadWorker& worker = (BadWorker&) worker_arg;
    QueueManager& manager = QueueManager::getInstance();
    
    cout << "Thread(" << pthread_self() << "):: Started" << endl;
    
    while (true){
        manager.getRequest(worker.current_job);
        assert(worker.current_job.connfd != JobEntry::NO_FD);
        worker.current_job.setTime(JobEntry::Dispatch);
        
        requestHandle(worker.current_job.connfd);
        manager.finishRequest(worker.current_job);
    }
}
void BadWorkerInit(BadWorker& worker){
    worker.current_job = (JobEntry::NO_FD);
    //worker.thread = thread;
}


