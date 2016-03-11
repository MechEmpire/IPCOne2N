//
// Created by jiang on 2016/3/11.
//

#ifndef IPC12N_DISTRIBUTION_IPC12N_OPT_COUNTER_H
#define IPC12N_DISTRIBUTION_IPC12N_OPT_COUNTER_H

int get_client_count();

const char *get_server_name();

void set_server_name(const char *name);

const char *get_client_name(int index);

void add_client(const char *name);

#endif //IPC12N_DISTRIBUTION_IPC12N_OPT_COUNTER_H
