//
// Created by jcy on 3/26/16.
//

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "client/ipc12n_client.h"

int main() {
    FILE *log_file = fopen("client_log.txt", "w");
    fprintf(log_file, "It's a log for client\n");
    fprintf(log_file, "I'm a client\n");

    const char str[] = "I'm returning to client";
    char buff[512];
    bzero(buff, sizeof(buff));

    if (-1 != read(server_fd, buff, sizeof(buff))) {
        fprintf(log_file, "Server 1 Return: %s\n", buff);

        write(server_fd, str, sizeof(str));
    } else {
        fprintf(log_file, "WTF Where is the server?\n");
    }


    fprintf(log_file, "End of log\n");
    return 0;
}