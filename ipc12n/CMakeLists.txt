cmake_minimum_required(VERSION 2.6.2)
project(ipc12n)


include_directories(
        ${ipc12n_SOURCE_DIR}/include
        ${ipc12n_SOURCE_DIR}
)

set(INTERNAL_HEADER_FILES
        include/internal/ipc12n_fd_operation.h
        include/internal/ipc12n_exec_process.h
        include/internal/ipc12n_opt_counter.h
        include/internal/ipc12n_opt_scanner.h
        include/internal/ipc12n_socket_pair.h
        )

set(INTERNAL_SOURCE_FILES
        src/internal/ipc12n_socket_pair.c
        src/internal/ipc12n_fd_operation.c
        src/internal/ipc12n_opt_scanner.c
        src/internal/ipc12n_opt_counter.c
        )

set(HEADER_FILES
        ${INTERNAL_HEADER_FILES}
        include/ipc12n_config.h
        include/client/ipc12n_client.h
        include/server/ipc12n_server.h)

set(SOURCE_FILES
        ${INTERNAL_SOURCE_FILES}
        src/main.c
        src/internal/ipc12n_exec_process.c)

add_executable(ipc12n ${HEADER_FILES} ${SOURCE_FILES})
