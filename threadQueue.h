//
// Created by guy cohen on 04/06/2022.
//

#ifndef WET_THREADQUEUE_H
#define WET_THREADQUEUE_H

#include <pthread.h>


class threadQueue {
private:
    pthread_mutex_t mutex;
    pthread_cond_t cond_write;
    int writers;
    
    int find(pthread_t thread_id);
    bool isEmpty();
    bool isFull();
    void printQueue();
public:
    
    static const int NotFound = -1;
    unsigned long max_size;
    unsigned long size;
    pthread_t* array;
    
    threadQueue(unsigned int maxSize);
    ~threadQueue();
    threadQueue(threadQueue&) = delete;
    threadQueue& operator=(threadQueue&) = delete;

    void insert(bool &result);
    void remove();
    

    
};






#endif //WET_THREADQUEUE_H
