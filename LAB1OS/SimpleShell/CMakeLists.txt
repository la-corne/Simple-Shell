cmake_minimum_required(VERSION 3.12)
project(SimpleShell)

set(CMAKE_CXX_STANDARD 11)

add_executable(SimpleShell main.cpp SynchronousProcesses.cpp SynchronousProcesses.h AsynchronousProcesses.cpp AsynchronousProcesses.h ReadAndSplitInstructions.cpp ReadAndSplitInstructions.h)