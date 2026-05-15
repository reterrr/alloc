cmake_minimum_required(VERSION 4.2)
project(alloc C)

set(CMAKE_C_STANDARD 11)

add_library(alloc STATIC
        alloc.c)

target_include_directories(alloc PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
add_executable(test test/main.c)
target_link_libraries(test PRIVATE alloc)
