//
// Created by jcy on 3/10/16.
//

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "internal/ipc12n_exec_process.h"
#include "internal/ipc12n_opt_scanner.h"
#include "internal/ipc12n_opt_counter.h"
#include "internal/ipc12n_socket_pair.h"

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

