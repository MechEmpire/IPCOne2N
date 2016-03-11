//
// Created by jiang on 2016/3/11.
//

#include "ipc12_socket_pair.h"
#include <sys/socket.h>

int create_socket_pair(int fd[2]) {
    return (socketpair(AF_UNIX, SOCK_STREAM, 0, fd));
}

void create_socket_pair_n(int fd[][2], int n) {
    for (int i = 0; i < n; i++) {
        create_socket_pair(fd[i]);
    }
}
