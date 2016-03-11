//
// Created by jcy on 3/11/16.
//

#ifndef IPC12N_DISTRIBUTION_IPC12N_EXEC_PROCESS_H
#define IPC12N_DISTRIBUTION_IPC12N_EXEC_PROCESS_H

void exec_server_process(int (*socket_pairs)[2]);

void exec_client_process(int (*socket_pairs)[2], int index);

#endif //IPC12N_DISTRIBUTION_IPC12N_EXEC_PROCESS_H
