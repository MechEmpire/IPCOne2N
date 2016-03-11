//
// Created by jiang on 2016/3/11.
//

#include "internal/ipc12n_opt_scanner.h"
#include <stdio.h>
#include <getopt.h>
#include "internal/ipc12n_opt_counter.h"

const struct option long_options[] = {
        {"client", required_argument, 0, 'c'},
        {"help",   no_argument,       0, 'h'},
        {"server", required_argument, 0, 's'},
        {0,        0,                 0, 0},
};

struct help {
    char value;
    const char *name;
    const char *discribtion;
};

const struct help helps[] = {
        {'c', "client", "set several client programs"},
        {'h', "help",   "display help and exit"},
        {'s', "server", "set one server program"},
};

static void print_help() {
    printf("Usage: ipc12n [OPTION]...\n");
    printf("Create ipc between client and server\n");
    printf("\n");

    int i;
    for (i = 0; i < sizeof(helps) / sizeof(struct help); i++) {
        printf("  -%c, --%-20s%s\n", helps[i].value, helps[i].name, helps[i].discribtion);
    }

    printf("\n");
    printf("Examples:\n");
    printf("  cat -h                 Display the help and exit\n");
    printf("  car -s s1 -c c1 -c c2  Run a server called s1 with two client called c1 and c2 \n");
    printf("\n");
}

int scan_opts(int argc, char **argv) {
    int ret = 0;
    while (-1 != (ret = getopt_long(argc, argv, "c:hs:", long_options, NULL))) {
        switch (ret) {
            case 'h': // option help
                print_help();
                return 0;
            case 's': // option server
                set_server_name(optarg);
                break;
            case 'c': // option client
                add_client(optarg);
                break;
            default:
                break;
        }
    }
    return 0;
}
