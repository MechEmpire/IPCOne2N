cmake_minimum_required(VERSION 2.6.2)
project(ipc12n)


include_directories(
        ${ipc12n_SOURCE_DIR}/include
        ${ipc12n_SOURCE_DIR}
)

set(SOURCE_FILES src/main.c)

add_executable(ipc12n ${SOURCE_FILES})