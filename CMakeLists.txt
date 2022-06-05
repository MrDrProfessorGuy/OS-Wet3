cmake_minimum_required(VERSION 3.19)
project(Wet)

set(CMAKE_CXX_STANDARD 11)

add_executable(Wet
        segel2.cpp segel2.h
        request2.cpp request2.h
        QueueManager.cpp QueueManager.h
        threadQueue.cpp threadQueue.h
        JobQueue.cpp JobQueue.h
        Worker.cpp Worker.h
        shit.cpp)