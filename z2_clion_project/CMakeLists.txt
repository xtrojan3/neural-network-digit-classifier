cmake_minimum_required(VERSION 3.26)
project(z2 C)

set(CMAKE_C_STANDARD 11)
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic")

add_executable(z2 src/functions.c src/data.c src/z2.c)
target_include_directories(z2 PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(z2 m)