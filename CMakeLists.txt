cmake_minimum_required(VERSION 3.26)
project(c_containers C)

set(CMAKE_C_STANDARD 11)

include_directories(include src)

add_library(c_containers library.c
        include/cc_vec.h
        src/cc_util.h
        src/cc_vec.c
        src/cc_err.h
        include/cc_sparse.h
        src/cc_sparse.c)

add_executable(c_containers_test test/main.c)
target_link_libraries(c_containers_test c_containers)