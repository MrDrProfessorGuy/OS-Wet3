//
// Created by guy cohen on 05/06/2022.
//

#ifndef WET_WORKER_H
#define WET_WORKER_H

#include "pthread.h"

extern class JobEntry;

class Worker {
private:
    JobEntry current_job;
    
public:
    Worker();
    ~Worker();
    
    Worker(Worker&) = delete;
    Worker& operator=(Worker&) = delete;
    
    void start();
    pthread_t thread;
};

typedef struct worket_t{
    JobEntry current_job;
    pthread_t thread;
}BadWorker;


void* startButInShittyCode(void* worker_arg);
void BadWorkerInit(BadWorker& worker);

#endif //WET_WORKER_H
