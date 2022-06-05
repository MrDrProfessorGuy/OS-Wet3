//
// Created by guy cohen on 04/06/2022.
//

#include "threadQueue.h"
#include "assert.h"

threadQueue::threadQueue(unsigned int maxSize){
    if (pthread_mutex_init(&mutex, nullptr) != 0){
        assert(false);
    }
    if (pthread_cond_init(&cond_write, nullptr) != 0){
        assert(false);
    }
    
    array = (pthread_t*)malloc(sizeof(pthread_t) * maxSize);
    if (array == nullptr){
        exit(0);
    }
    size = 0;
    max_size = maxSize;
    
}
threadQueue::~threadQueue(){
    assert(array != nullptr);
    free(array);
}

bool threadQueue::isEmpty() const{
    if (size == 0){
        return true;
    }
    return false;
}
bool threadQueue::isFull() const{
    if (size == max_size){
        return true;
    }
    return false;
}

void threadQueue::insert(bool &result){
    pthread_mutex_lock(&mutex);
    while(writers > 0){
        pthread_cond_wait(&cond_write, &mutex);
    }
    writers++;
    
    assert(find(pthread_self()) == NotFound);
    result = true;
    if (isFull()){
        result = false;
    }
    else{
        array[size] = pthread_self();
        size++;
    }
    
    writers--;
    pthread_cond_signal(&cond_write);
    pthread_mutex_unlock(&mutex);
}

void threadQueue::remove(){
    pthread_mutex_lock(&mutex);
    assert(!isEmpty());
    while (writers > 0 || isEmpty()){
        pthread_cond_wait(&cond_write, &mutex);
        assert(!isEmpty());
    }
    writers++;
    
    assert(!isEmpty());
    int index = find(pthread_self());
    assert(index > NotFound);
    for (int idx = index; idx < max_size-1; idx++) {
        array[idx] = (array[idx + 1]);
    }
    size--;
    
    writers--;
    pthread_cond_signal(&cond_write);
    pthread_mutex_unlock(&mutex);
}

int threadQueue::find(pthread_t thread_id) const{
    for(int i = 0; i < size; i++){
        if(pthread_equal(array[i], thread_id)){
            return i;
        }
    }
    return NotFound;
}
/*

void threadQueue::printQueue() const{
    for(int i = 0; i < size; i++){
        std::cout << array[i] << std::endl;
    }
}*/
