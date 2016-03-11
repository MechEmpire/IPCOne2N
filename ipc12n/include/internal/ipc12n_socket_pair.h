//
// Created by jiang on 2016/3/11.
//

#ifndef IPC12N_DISTRIBUTION_IPC_SOCKET_PAIR_H
#define IPC12N_DISTRIBUTION_IPC_SOCKET_PAIR_H

/*
 * Return a full-duplex "stream" pipe (a Unix domain socket)
 * with the two file descripors return in fd[0] and fd[1]
 */
int create_socket_pair(int fd[2]);

/*
 * Return an array of full-duplex "stream" pipe (a Unix domain socket)
 * with the two file descripors return in fd[][0] and fd[][1]
 */
void create_socket_pair_n(int fd[][2],int n);

#endif //IPC12N_DISTRIBUTION_IPC_SOCKET_PAIR_H
