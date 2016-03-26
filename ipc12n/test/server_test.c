//
// Created by jcy on 3/26/16.
//

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "server/ipc12n_server.h"

int main() {
    FILE *log_file = fopen("server_log.txt", "w");
    fprintf(log_file, "It's a log for server\n");
    fprintf(log_file, "I'm a server\n");

    const char str[] = "I'm saying to client";
    char buff[512];
    bzero(buff, sizeof(buff));

    write(client_fd(1), str, sizeof(str));

    if (-1 == read(client_fd(1), buff, sizeof(buff)))
        fprintf(log_file, "Where is Client?\n");
    else
        fprintf(log_file, "Client Return: %s\n", buff);


    fprintf(log_file, "End of log\n");
    return 0;
}