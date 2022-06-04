cmake_minimum_required(VERSION 3.19)
project(Wet)

set(CMAKE_CXX_STANDARD 11)

add_executable(Wet main.cpp


        QueueManager.cpp QueueManager.h
        test.h
        threadQueue.cpp threadQueue.h JobQueue.cpp JobQueue.h)