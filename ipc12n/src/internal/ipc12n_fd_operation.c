//
// Created by jiang on 2016/3/11.
//

#include "internal/ipc12n_fd_operation.h"
#include <unistd.h>
#include "ipc12n_config.h"

void close_all_server_fd(int (*fd)[2], int n) {
    for (int i = 0; i < n; i++) {
        close(fd[i][kFdConnectToServer]);
    }
}

void close_all_client_fd_except(int (*fd)[2], int n, int except) {
    for (int i = 0; i < n; i++) {
        if (i != except) {
            close(fd[i][kFdConnectToClient]);
        }
    }
}

void move_fd(int new_fd, int old_fd) {
    if (new_fd != old_fd) {
        dup2(new_fd, old_fd);
        close(old_fd);
    }
}
