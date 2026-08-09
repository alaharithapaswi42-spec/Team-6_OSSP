# OSSP - Mini Shell

## Project Description

This project is a basic command-line shell developed as part of the OSSP practical.

The shell demonstrates process creation and command execution using the `fork()` and `exec()` system calls.

## Features

- Display a shell prompt
- Accept commands from the user
- Parse commands and arguments
- Create child processes using `fork()`
- Execute commands using `execvp()`
- Wait for child processes using `wait()`
- Support the built-in `cd` command
- Support the `exit` command

## Project Structure

```text
OSSP/
├── .gitignore
├── README.md
├── Makefile
├── src/
│   ├── main.c
│   ├── shell.c
│   ├── parser.c
│   ├── executor.c
│   └── builtin.c
├── include/
│   ├── shell.h
│   ├── parser.h
│   ├── executor.h
│   └── builtin.h
├── obj/
├── bin/
├── docs/
├── tests/
├── scripts/
└── assets/
