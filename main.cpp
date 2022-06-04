#include <iostream>
#include "test.h"
#include "threadQueue.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    

    threadQueue queue(20);
    std::cout << "============= Insert Test =============" << std::endl;
    for (int id = 0; id < queue.max_size; id++) {
        queue.insert(id);
        int found = queue.find(id);
        std::cout << "id[" << id << "]: ";
        if (found == threadQueue::NotFound){
            std::cout << "Not ";
        }
        std::cout << "Found" << std::endl;
    }
    std::cout << "queue: " << std::endl;
    queue.printQueue();
    
    std::cout << "=========Remove_Test=========" << std::endl;
    for (int id = 0; id < queue.max_size; id++) {
        if(id % 2 == 0){
            queue.remove(id);
        }
        int found = queue.find(id);
        std::cout << "id[" << id << "]: ";
        if (found == threadQueue::NotFound){
            std::cout << "Not ";
        }
        std::cout << "Found" << std::endl;
    }
    if(queue.size != queue.max_size/2){
        std::cout << "Remove::Queue size is not valid" << std::endl;
    }
    std::cout << "queue: " << std::endl;
    queue.printQueue();
    
    for (int id = 0; id < queue.max_size; id++) {
        if(id % 2 != 0){
            queue.remove(id);
        }
        int found = queue.find(id);
        std::cout << "id[" << id << "]: ";
        if (found == threadQueue::NotFound){
            std::cout << "Not ";
        }
        std::cout << "Found" << std::endl;
    }
    if(!queue.isEmpty()){
        std::cout << "Remove::Queue is not empty" << std::endl;
    }
    std::cout << "queue: " << std::endl;
    queue.printQueue();
    return 0;
}
