cmake_minimum_required(VERSION 3.9)
project(e2)

set(CMAKE_CXX_STANDARD 17)

find_package (Threads)
add_executable(e2 main.cc e2.h c2.cc)
target_link_libraries (e2 ${CMAKE_THREAD_LIBS_INIT})