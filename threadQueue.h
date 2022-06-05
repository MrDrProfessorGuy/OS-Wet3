//
// Created by guy cohen on 04/06/2022.
//

#ifndef WET_THREADQUEUE_H
#define WET_THREADQUEUE_H

#include <pthread.h>

#ifndef WET_JOBQUEUE_H
class QueueManager;
#endif //WET_JOBQUEUE_H


class threadQueue {
private:
    pthread_mutex_t mutex;
    pthread_cond_t cond_write;
    int writers;
    
    static const int NotFound = -1;
    long max_size;
    long size;
    pthread_t* array;
    
protected:
    bool isEmpty() const;
    bool isFull() const;
    int find(pthread_t thread_id) const;
    //void printQueue() const;
public:
    friend class QueueManager;

    
    threadQueue(unsigned int maxSize);
    ~threadQueue();
    threadQueue(threadQueue&) = delete;
    threadQueue& operator=(threadQueue&) = delete;

    void insert(bool &result);
    void remove();
    

    
};






#endif //WET_THREADQUEUE_H
