//
// Created by jcy on 3/10/16.
//


#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>

#include "server/ipc12n_server.h"
#include "client/ipc12n_client.h"

/*
 * Return a full-duplex "stream" pipe (a Unix domain socket)
 * with the two file descripors return in fd[0] and fd[1]
 */
int s_pipe(int fd[2]);

/*
 * Change a fd from one value to another
 */
void dup_fd_2_fd(int new_fd, int old_fd);

int main(int argc,char * argv[])
{
    int fd[argc - 2][2];

    for (int i = 0; i < argc - 2; i++)
    {
        s_pipe(fd[i]);
    }

    pid_t pid;

    for (int i = 0; i < argc - 1; i++) {
        pid = fork();
        if (pid == 0) {
            //for child process
            //change all the fd to the one in the defined file
            if (i) {
                for (int j = 0; j < argc - 2; j++) {
                    close(fd[j][1]);
                    dup_fd_2_fd((int) (client_fd(j)), fd[j][0]);
                }
            }
            else {
                int client_fd = fd[i - 1][1];
                for (int j = 0; j < argc - 2; j++) {
                    close(fd[j][0]);
                    if (i - 1 != j) {
                        close(fd[j][0]);
                    }
                }
                dup_fd_2_fd((int) server_fd, client_fd);
            }

            //exec the process
            execv(argv[i + 2], NULL);

            //exit
            exit(0);
        }
    }

    //for parent process
    if (pid != 0) {
        //wait all the child process to exit
        wait(NULL);
    }

}


int s_pipe(int fd[2]) {
    return (socketpair(AF_UNIX, SOCK_STREAM, 0, fd));
}

void dup_fd_2_fd(int new_fd, int old_fd) {
    if (new_fd != old_fd) {
        dup2(new_fd, old_fd);
        close(old_fd);
    }
}