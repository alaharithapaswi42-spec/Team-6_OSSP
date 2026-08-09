#include <stdio.h>
#include "parser.h"

int main() {
    char command[] = "ls -l";
    char *args[MAX_ARGS];

    parse_command(command, args);

    printf("Command: %s\n", args[0]);
    printf("Argument: %s\n", args[1]);

    return 0;
}
