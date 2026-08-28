#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#define MAX_HISTORY 10
#define MAX_INPUT 100

char history[MAX_HISTORY][MAX_INPUT];
int history_count = 0;

void disableRawMode(struct termios *original) {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, original);
}

void enableRawMode(struct termios *original) {
    struct termios raw;

    tcgetattr(STDIN_FILENO, original);
    raw = *original;

    raw.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void storeCommand(char *input) {
    if (strlen(input) == 0)
        return;

    if (history_count < MAX_HISTORY) {
        strcpy(history[history_count], input);
        history_count++;
    } else {
        for (int i = 1; i < MAX_HISTORY; i++)
            strcpy(history[i - 1], history[i]);

        strcpy(history[MAX_HISTORY - 1], input);
    }
}

int main() {
    struct termios original;
    char input[MAX_INPUT];
    int length;
    int history_index;

    enableRawMode(&original);

    while (1) {
        printf("\nmyshell> ");
        fflush(stdout);

        length = 0;
        history_index = history_count;

        while (1) {
            char c;

            if (read(STDIN_FILENO, &c, 1) <= 0)
                break;

            /* Enter key */
            if (c == '\n' || c == '\r') {
                input[length] = '\0';
                printf("\n");
                break;
            }

            /* Backspace */
            if (c == 127 || c == '\b') {
                if (length > 0) {
                    length--;
                    input[length] = '\0';

                    printf("\b \b");
                    fflush(stdout);
                }
                continue;
            }

            /* Escape sequence */
            if (c == 27) {
                char seq[2];

                if (read(STDIN_FILENO, &seq[0], 1) <= 0)
                    continue;

                if (seq[0] != '[')
                    continue;

                if (read(STDIN_FILENO, &seq[1], 1) <= 0)
                    continue;

                /* Up arrow */
                if (seq[1] == 'A') {
                    if (history_count > 0 && history_index > 0) {
                        history_index--;

                        printf("\r\033[Kmyshell> %s",
                               history[history_index]);

                        strcpy(input, history[history_index]);
                        length = strlen(input);

                        fflush(stdout);
                    }
                }

                /* Down arrow */
                else if (seq[1] == 'B') {
                    if (history_index < history_count - 1) {
                        history_index++;

                        printf("\r\033[Kmyshell> %s",
                               history[history_index]);

                        strcpy(input, history[history_index]);
                        length = strlen(input);

                        fflush(stdout);
                    } else {
                        history_index = history_count;
                        length = 0;
                        input[0] = '\0';

                        printf("\r\033[Kmyshell> ");
                        fflush(stdout);
                    }
                }

                continue;
            }

            /* Normal character */
            if (length < MAX_INPUT - 1) {
                input[length++] = c;
                input[length] = '\0';

                putchar(c);
                fflush(stdout);
            }
        }

        if (strcmp(input, "exit") == 0)
            break;

        storeCommand(input);
    }

    disableRawMode(&original);

    printf("\nExiting shell...\n");

    return 0;
}
