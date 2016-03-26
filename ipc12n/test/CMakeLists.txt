cmake_minimum_required(VERSION 2.6.2)
project(test)

include_directories(
        ${ipc12n_SOURCE_DIR}/include
        ${ipc12n_SOURCE_DIR}
)

add_executable(server_test server_test.c)

add_executable(client_test client_test.c)