

#ifndef WET_QUEUEMANAGER_H
#define WET_QUEUEMANAGER_H

#include <sys/socket.h>
#include <iostream>

#include "JobQueue.h"
#include "threadQueue.h"

#include "assert.h"




class QueueManager{
private:
    pthread_mutex_t mutex;
    pthread_cond_t cond_write;
    pthread_cond_t cond_read;
    int writers;
    
    unsigned int max_size;
    unsigned int size;
    
    threadQueue thread_queue;
    JobQueue jobs_queue;
    
public:
    explicit QueueManager(int max_size) : writers(0), max_size(max_size), size(0),
                                        thread_queue(max_size), jobs_queue(max_size){
        if (pthread_mutex_init(&mutex, nullptr) != 0){
            assert(false);
        }
        if (pthread_cond_init(&cond_write, nullptr) != 0){
            assert(false);
        }
        
    }
    
    ~QueueManager();
    
    QueueManager(QueueManager&) = delete;
    QueueManager& operator=(QueueManager&) = delete;
    
    void createJob(JobEntry job);
    //JobEntry getJob();
    void getRequest(JobEntry &job);
    void finishRequest(JobEntry &job);
    
    bool isFull();
    bool isEmpty();
    unsigned int maxSize();
    unsigned int Size();
    void increaseSize();
    void decreaseSize();
    bool contains(JobEntry job);
    
    bool lockAcquired(){
        if (pthread_mutex_trylock(&mutex) != 0){
            return false;
        }
        pthread_mutex_unlock(&mutex);
        return true;
    }
    
};





#endif //WET_QUEUEMANAGER_H
