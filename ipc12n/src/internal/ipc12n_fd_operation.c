//
// Created by jiang on 2016/3/11.
//

#include "ipc12n_config.h"
#include "internal/ipc12n_fd_operation.h"

void close_all_server_fd(int (*fd)[2], int n) {
    for (int i = 0; i < n; i++) {
        close(fd[i][kServer]);
    }
}

void close_all_client_fd_except(int (*fd)[2], int n, int except) {
    for (int i = 0; i < n; i++) {
        if (i != except) {
            close(fd[i][kClient]);
        }
    }
}

void move_fd(int new_fd, int old_fd) {
    if (new_fd != old_fd) {
        dup2(new_fd, old_fd);
        close(old_fd);
    }
}
