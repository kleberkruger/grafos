cmake_minimum_required(VERSION 3.14)
project(graph_apps)

set(CMAKE_CXX_STANDARD 17)

add_executable(graph_apps src/main.cpp src/core/application.h src/core/graphapp.h src/mstapp.h src/pathsapp.h src/flowsapp.h src/core/graph.cpp src/core/graph.h)