
#ifndef WET_QUEUEMANAGER_H
#define WET_QUEUEMANAGER_H


#include "JobQueue.h"
#include "threadQueue.h"



class QueueManager{
public:
    enum PolicyType {Block, DropRandom, DropTail, DropHead};
    //static QueueManager& instance;
    
private:
    pthread_mutex_t mutex;
    pthread_cond_t cond_write;
    pthread_cond_t cond_master;
    int handlers;
    int master_waiting;
    
    int max_size;
    int size;
    
    threadQueue thread_queue;
    JobQueue jobs_queue;
    PolicyType policy;
    
    //QueueManager(int max_size, PolicyType policy);
    
public:
    QueueManager();
    ~QueueManager();
    
    QueueManager(QueueManager&) = delete;
    QueueManager& operator=(QueueManager&) = delete;
    
    static QueueManager& getInstance();
    
    void createJob(JobEntry job);
    //JobEntry getJob();
    void getRequest(JobEntry &job);
    void finishRequest(JobEntry &job);
    
    bool isFull();
    bool isEmpty();
    int maxSize();
    int Size();
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
    void Initialize(int maxSize, PolicyType manager_policy){
        policy = manager_policy;
        jobs_queue.Initialize(maxSize);
        thread_queue.Initialize(maxSize);
    }
    
};



#endif //WET_QUEUEMANAGER_H
