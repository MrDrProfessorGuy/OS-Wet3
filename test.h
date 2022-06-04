
#ifndef WET_LIST_H
#define WET_LIST_H
#include "QueueManager.h"

class List{
    static const int NotFound = -1;
public:
    unsigned int max_size;
    unsigned int size;
    JobEntry* array;
    
    List(unsigned int maxSize){
        array = (JobEntry*)malloc(sizeof(JobEntry) * maxSize);
        if (array == nullptr){
            exit(0);
        }
        size = 0;
        max_size = maxSize;
        
    }
    ~List(){
        assert(array != nullptr);
        free(array);
    }
    
    List(List&) = delete;
    List& operator=(List&) = delete;
    
    bool isEmpty(){
        if (size == 0){
            return true;
        }
        return false;
    }
    bool isFull(){
        if (size == max_size){
            return true;
        }
        return false;
    }
    
    bool insert(JobEntry &job){
        if (isFull()){
            return false;
        }
        array[size].operator=(job);
        size++;
        return true;
    }
    
    void remove(JobEntry &job){
        if (isEmpty()){
            return;
        }
        int index = find(job);
        for (int idx = index; idx < max_size-1; idx++) {
            array[idx].operator=(array[idx + 1]);
        }
        size--;
    }
    
    int find(JobEntry &job){
        for(int i = 0; i < this->size; i++){
            if(this->array[i] == job){
                return i;
            }
        }
        return NotFound;
    }
    
};










#endif









