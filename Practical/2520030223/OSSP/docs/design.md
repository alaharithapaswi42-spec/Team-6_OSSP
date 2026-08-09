# Mini Shell Design

## 1. Introduction

The Mini Shell is a basic command-line shell developed as part of the OSSP practical.

The project demonstrates process creation and command execution using the `fork()` and `exec()` system calls.

## 2. Shell Architecture

The shell is divided into the following components:

```text
User
  |
  v
main.c
  |
  v
shell.c
  |
  v
parser.c
  |
  v
builtin.c / executor.c
  |
  v
fork()
  |
  +----------------+
  |                |
Parent           Child
  |                |
wait()           execvp()
                   |
                   v
             Linux Command
