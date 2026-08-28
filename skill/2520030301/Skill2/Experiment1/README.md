SKILL WEEK 2 - EXPERIMENT 1

Title:
To Create Main Loop, Display Prompt, Read User Input, Handle Exit Conditions, Design Control Flow Diagram, Test Interactive Loop

Objective:
To create a basic interactive shell loop that displays a prompt, reads user input, handles the exit condition, and displays the entered command.

Program:
shell1.c

Description:
The program continuously displays the "myshell>" prompt and waits for user input. The fgets() function reads the input from the user. The newline character is removed using strcspn(). If the user enters "exit", the shell displays an exit message and terminates. Otherwise, the entered command is displayed.

Compilation:
gcc shell1.c -o shell1

Execution:
./shell1

Expected Behavior:
The shell repeatedly accepts input until the user enters "exit".

Sample:
myshell> ls
You entered: ls
myshell> pwd
You entered: pwd
myshell> hello
You entered: hello
myshell> exit
Exiting shell...
