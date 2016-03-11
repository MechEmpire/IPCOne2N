//
// Created by jcy on 3/10/16.
//

#include <stdio.h>
#include <unistd.h>
#include "internal/ipc12n_fd_operation.h"
#include "internal/ipc12n_opt_scanner.h"
#include "internal/ipc12n_opt_counter.h"
#include "internal/ipc12n_socket_pair.h"
#include "server/ipc12n_server.h"
#include "client/ipc12n_client.h"

void exec_server_process(int (*socket_pairs)[2]);

void exec_client_process(int (*socket_pairs)[2], int index);

int main(int argc, char *argv[]) {
    scan_opts(argc, argv);

    const int client_num = get_client_count();
    int socket_pairs[client_num][2];
    create_socket_pair_n(socket_pairs, client_num);

    exec_server_process(socket_pairs);
    for (int i = 0; i < argc - 1; i++) {
        exec_client_process(socket_pairs, i);
    }

    wait(NULL);
    return 0;
}

void exec_server_process(int (*socket_pairs)[2]) {
    pid_t pid = fork();
    if (pid == 0) {
        const int client_num = get_client_count();
        close_all_client_fd_except(socket_pairs, client_num, -1);
        for (int i = 0; i < client_num; i++) {
            move_fd(client_fd(i), socket_pairs[i][kServer]);
        }
        execv(get_server_name(), NULL);
        exit(0);
    }
}

void exec_client_process(int (*socket_pairs)[2], int index) {
    pid_t pid = fork();
    if (pid == 0) {
        const int client_num = get_client_count();
        close_all_client_fd_except(socket_pairs, client_num, -1);
        close_all_server_fd(socket_pairs, client_num);
        move_fd(server_fd, socket_pairs[index][kClient]);
        execv(get_client_name(index), NULL);
        exit(0);
    }
}
