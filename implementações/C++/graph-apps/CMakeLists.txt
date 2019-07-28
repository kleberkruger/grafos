cmake_minimum_required(VERSION 3.14)
project(graph_apps)

set(CMAKE_CXX_STANDARD 17)

add_executable(graph_apps
        src/core/djset/disjointset.h src/core/djset/listset.h src/core/djset/unionfind.h
        src/core/heap/heap.h src/core/heap/arrayheap.h src/core/heap/binaryheap.h src/core/heap/fibonacciheap.h
        src/core/application.h src/core/graphapp.h
        src/mstapp.h src/pathsapp.h src/flowsapp.h src/core/graph.cpp src/core/graph.h
        src/main.cpp)
