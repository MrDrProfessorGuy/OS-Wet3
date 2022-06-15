//
// Created by guy cohen on 04/06/2022.
//

#ifndef WET_JOBSQUEUE_H
#define WET_JOBSQUEUE_H

#include <sys/time.h>
#include <pthread.h>

#ifndef WET_QUEUEMANAGER_H
class QueueManager;
#endif //WET_QUEUEMANAGER_H

typedef struct timeval TimeInfo;

class JobEntry{
public:
    static const int NO_FD = -1;
    enum Time {Arrival, Dispatch};
    int connfd;
    TimeInfo arrival_time;
    TimeInfo dispatch_time;
    
    
    explicit JobEntry(int connfd);
    ~JobEntry();
    
    JobEntry(JobEntry &job);
    JobEntry& operator=(JobEntry& job ) = default;
    JobEntry operator=(int fd){
        JobEntry job(fd);
        return job;
    }
    
    void setTime(Time timeField);
    
};

bool operator==(const JobEntry &job1, const JobEntry& job2);



class JobsQueue{
    static const int NotFound = -1;
    
    pthread_mutex_t mutex;
    pthread_cond_t cond_write;
    int writers;
    
    int front;
    int rear;
    
    int max_size;
    int size;
    JobEntry* array;

protected:
    bool isEmpty() const;
    bool isFull() const;
    int find(JobEntry &job) const;
    friend class QueueManager;
    void Initialize(int maxSize);
public:
    
    explicit JobQueue();
    ~JobQueue();
    
    JobQueue(JobQueue&) = delete;
    JobQueue& operator=(JobQueue&) = delete;
    
    void insert(JobEntry &job, bool &result);
    void pop(JobEntry &job, int index=0);
    
};



#endif //WET_JOBSQUEUE_H
