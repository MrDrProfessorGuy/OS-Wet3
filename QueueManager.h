
#ifndef WET_QUEUEMANAGER_H
#define WET_QUEUEMANAGER_H


#include "JobQueue.h"
#include "threadQueue.h"


class QueueManager{
public:
    enum PolicyType {Block, DropRandom, DropTail, DropHead};
    static QueueManager& instance;
    
private:
    pthread_mutex_t mutex;
    pthread_cond_t cond_write;
    pthread_cond_t cond_master;
    int handlers;
    int master_waiting;
    
    unsigned int max_size;
    unsigned int size;
    
    threadQueue thread_queue;
    JobQueue jobs_queue;
    PolicyType policy;
    
    QueueManager(int max_size, PolicyType policy);
public:
    
    ~QueueManager();
    
    QueueManager(QueueManager&) = delete;
    QueueManager& operator=(QueueManager&) = delete;
    
    static QueueManager& getInstance();
    static QueueManager& AuxGetInstance(int max_size, PolicyType policy);
    
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
    bool policyHandler(JobEntry &job);
    
    bool lockAcquired(){
        if (pthread_mutex_trylock(&mutex) != 0){
            return false;
        }
        pthread_mutex_unlock(&mutex);
        return true;
    }
    
};





#endif //WET_QUEUEMANAGER_H
