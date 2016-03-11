cmake_minimum_required(VERSION 2.6.2)
project(ipc12n)


include_directories(
        ${ipc12n_SOURCE_DIR}/include
        ${ipc12n_SOURCE_DIR}
)

set(INTERNAL_SOURCE_FILES
        #        src/internal/ipc12n_socket_pair.c
        #        src/internal/ipc12n_fd_operation.c
        src/internal/ipc12n_opt_scanner.c
        )

set(SOURCE_FILES
        ${INTERNAL_SOURCE_FILES}
        src/main.c include/internal/ipc12n_opt_counter.h src/internal/ipc12n_opt_counter.c)

add_executable(ipc12n ${SOURCE_FILES})


#TODO add test and fix self-annotated code