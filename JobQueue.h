//
// Created by guy cohen on 04/06/2022.
//

#ifndef WET_JOBQUEUE_H
#define WET_JOBQUEUE_H

#include <sys/time.h>
#include <pthread.h>



typedef struct timeval TimeInfo;

class JobEntry{
public:
    static const int NO_FD = -1;
    enum Time {Arrival, Dispatch};
    int connfd;
    TimeInfo arrival_time;
    TimeInfo dispatch_time;
    
    
    JobEntry(int connfd);
    ~JobEntry();
    
    JobEntry(JobEntry &job);
    JobEntry& operator=(JobEntry& job);
    
    void setTime(Time timeField);
    
};

bool operator==(const JobEntry &job1, const JobEntry& job2);



class JobQueue{
    static const int NotFound = -1;
    
    pthread_mutex_t mutex;
    pthread_cond_t cond_write;
    int writers;
    
    bool isEmpty();
    bool isFull();
    int find(JobEntry &job);

public:
    unsigned int max_size;
    unsigned int size;
    JobEntry* array;
    
    JobQueue(unsigned int maxSize);
    ~JobQueue();
    
    JobQueue(JobQueue&) = delete;
    JobQueue& operator=(JobQueue&) = delete;
    
    void insert(JobEntry &job, bool &result);
    void pop(JobEntry &job);
    
};



#endif //WET_JOBQUEUE_H
