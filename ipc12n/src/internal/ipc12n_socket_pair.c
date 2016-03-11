//
// Created by jiang on 2016/3/11.
//

#include <sys/socket.h>
#include "internal/ipc12n_socket_pair.h"

int create_socket_pair(int fd[2]) {
    return (socketpair(AF_UNIX, SOCK_STREAM, 0, fd));
}

void create_socket_pair_n(int fd[][2], int n) {
    for (int i = 0; i < n; i++) {
        create_socket_pair(fd[i]);
    }
}
