#include <stdio.h>
#include "executor.h"

int main() {
    char *args[] = {"echo", "Executor test successful", NULL};

    execute_command(args);

    return 0;
}
