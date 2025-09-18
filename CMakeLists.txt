cmake_minimum_required(VERSION 3.10)
PROJECT(Vector)

set(CMAKE_CXX_STANDARD 23)

add_executable(main
    main.cpp
)

target_include_directories(main PRIVATE vector.cpp)