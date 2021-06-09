cmake_minimum_required(VERSION 3.17)
project(LABA2)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(tests)

add_executable(MAT main.cpp DynamicArray.h LinkedList.h Sequence.h ArraySequence.h ListSequence.h Complex.h Matrix.h  menu.h)

