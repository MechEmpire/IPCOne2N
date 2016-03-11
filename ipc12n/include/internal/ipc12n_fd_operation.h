//
// Created by jiang on 2016/3/11.
//

#ifndef IPC12N_DISTRIBUTION_IPC12N_FD_OPERATION_H
#define IPC12N_DISTRIBUTION_IPC12N_FD_OPERATION_H

void close_all_server_fd(int (*fd)[2], int n);

void close_all_client_fd_except(int (*fd)[2], int n, int except);

void move_fd(int new_fd,int old_fd);

#endif //IPC12N_DISTRIBUTION_IPC12N_FD_OPERATION_H
