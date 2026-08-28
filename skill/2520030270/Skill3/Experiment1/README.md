SKILL WEEK 3 - EXPERIMENT 1

Title:
To Apply Escape Sequences, Store Command History, Navigate Previous Commands, Navigate Next Commands, Update Input Buffer, Test Recall Functionality.

Objective:
To implement command history functionality in a simple shell using escape sequences. The program stores previously entered commands and allows the user to navigate through previous and next commands using the Up and Down arrow keys.

Program:
command_history.c

Description:
The program implements an interactive shell that accepts user commands.

The program:
1. Displays the myshell prompt.
2. Reads user input character by character.
3. Stores entered commands in a command history.
4. Uses escape sequences to detect the Up and Down arrow keys.
5. Uses the Up arrow to recall previous commands.
6. Uses the Down arrow to navigate to newer commands.
7. Updates the input buffer when a command is recalled.
8. Uses backspace to modify the input buffer.
9. Limits the history to a fixed number of commands.
10. Terminates when the user enters exit.

Escape Sequences:
Up Arrow: ESC [ A
Down Arrow: ESC [ B

Compilation:
gcc command_history.c -o command_history

Execution:
./command_history

Testing:
Enter multiple commands such as:

ls
pwd
gcc test.c

Press the Up arrow to recall previously entered commands.
Press the Down arrow to navigate forward through command history.
Enter exit to terminate the shell.

Expected Result:
The previously entered commands can be recalled using the Up arrow and the next commands can be accessed using the Down arrow. The input buffer is updated whenever a command is recalled.
