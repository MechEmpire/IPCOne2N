//
// Created by jcy on 3/11/16.
//

#include <stdlib.h>
#include <unistd.h>
#include "client/ipc12n_client.h"
#include "internal/ipc12n_exec_process.h"
#include "internal/ipc12n_fd_operation.h"
#include "internal/ipc12n_opt_counter.h"
#include "server/ipc12n_server.h"

void exec_server_process(int (*socket_pairs)[2]) {
    __darwin_pid_t pid = fork();
    if (pid == 0) {
        const int client_num = get_client_count();
        close_all_client_fd_except(socket_pairs, client_num, -1);
        for (int i = 0; i < client_num; i++) {
            move_fd(client_fd(i), socket_pairs[i][kFdConnectToServer]);
        }
        execv(get_server_name(), NULL);
        exit(0);
    }
}

void exec_client_process(int (*socket_pairs)[2], int index) {
    __darwin_pid_t pid = fork();
    if (pid == 0) {
        const int client_num = get_client_count();
        close_all_client_fd_except(socket_pairs, client_num, index);
        close_all_server_fd(socket_pairs, client_num);
        move_fd(server_fd, socket_pairs[index][kFdConnectToClient]);
        execv(get_client_name(index), NULL);
        exit(0);
    }
}