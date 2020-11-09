cmake_minimum_required(VERSION 3.17)
project(CPP)

set(CMAKE_CXX_STANDARD 20)


add_executable(BubbleSort BubbleSort.cpp)
add_executable(SelectionSort SelectionSort.cpp)
add_executable(ShellSort ShellSort.cpp)
add_executable(testDivide testDivide.cpp)