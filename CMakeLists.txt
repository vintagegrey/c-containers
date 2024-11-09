cmake_minimum_required(VERSION 3.26)
project(c_containers C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(SRC
    src/cc_util.h
    src/cc_vec.c
    src/cc_err.h
    src/cc_sparse.c)

add_library(c_containers STATIC ${SRC}
        include/c_containers.h)

include_directories(include src)
target_include_directories(c_containers PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(c_containers_test test/main.c)
target_link_libraries(c_containers_test PRIVATE c_containers)