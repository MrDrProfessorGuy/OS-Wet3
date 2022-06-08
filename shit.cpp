#include "segel2.h"
#include "Worker.h"
#include "QueueManager.h"

#include "iostream"
using namespace std;
//
// server.c: A very, very simple web server
//
// To run:
//  ./server <portnum (above 2000)>
//
// Repeatedly handles HTTP requests sent to this port number.
// Most of the work is done within routines written in request.c
//

void unix_error(char *msg);


// HW3: Parse the new arguments too
void getargs(int *port, int *threads_num, int *queue_size, char** schedalg, int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }
    *port = atoi(argv[1]);
    *threads_num = atoi(argv[2]);
    *queue_size = atoi(argv[3]);
    *schedalg = argv[4];
}


int main(int argc, char *argv[])
{
    int listenfd, connfd, port, clientlen, threads_num, queue_size;
    char* schedalg;
    struct sockaddr_in clientaddr;
    
    getargs(&port, &threads_num, &queue_size, &schedalg, argc, argv);
    
    //
    // HW3: Create some threads...
    //
    QueueManager::PolicyType policy;
    if (strcmp(schedalg,"block") == 0){
        policy = QueueManager::Block;
    }
    if (strcmp(schedalg,"dt") == 0){
        policy = QueueManager::DropTail;
    }
    if (strcmp(schedalg,"dh") == 0){
        policy = QueueManager::DropHead;
    }
    if (strcmp(schedalg,"random") == 0){
        policy = QueueManager::DropRandom;
    }
    
    cout << "=======================================================================" << endl;
    cout << "=========================== Server Starting ===========================" << endl;
    cout << "=======================================================================" << endl;
    
    cout << "=========================== Creating Threads ===========================" << endl;
    
    QueueManager& manager = QueueManager::getInstance();
    manager.Initialize(queue_size, policy);
    BadWorker* workers = (BadWorker *) malloc(sizeof(BadWorker)*threads_num);
    for (int thread = 0; thread < threads_num; thread++) {
        BadWorkerInit(workers[thread], thread);
        if (pthread_create(&(workers[thread].thread), NULL, startButInShittyCode, (void*)(&workers[thread])) != 0){
            unix_error("pthread_create error");
        }
    }
    cout << "=========================== Threads Were Created ===========================" << endl;
    
    
    listenfd = Open_listenfd(port);
    while (1) {
        clientlen = sizeof(clientaddr);
        connfd = Accept(listenfd, (SA *)&clientaddr, (socklen_t *) &clientlen);
        JobEntry new_job(connfd);
        cout << "Master::New Connection{ fd="<<connfd<<" }" << endl;
        manager.createJob(new_job);
        
        //
        // HW3: In general, don't handle the request in the main thread.
        // Save the relevant info in a buffer and have one of the worker threads
        // do the work.
        //
        //requestHandle(connfd);
        
        //Close(connfd);
    }
    
    
}






