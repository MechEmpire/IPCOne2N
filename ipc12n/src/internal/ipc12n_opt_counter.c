//
// Created by jiang on 2016/3/11.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "internal/ipc12n_opt_counter.h"

static int client_count = 0;
static char server_name[256] = "";
static char *client_name[256] = {0};

int get_client_count() {
    return client_count;
}

const char *get_server_name() {
    return server_name;
}

void set_server_name(const char *name) {
    if (strcmp(name, "") == 0) {
        strcpy(server_name, name);
    } else {
        perror("set the server twice!");
        exit(1);
    }
}

const char *get_client_name(int index) {
    assert(index < client_count);
    return client_name[index];
}

void add_client(const char *name) {
    client_name[client_count] = malloc(strlen(name) + 1);
    strcpy(client_name[client_count], name);
    ++client_count;
}
