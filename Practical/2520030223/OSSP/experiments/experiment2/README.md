# Experiment 2 - Process State Transitions

## Aim

To develop a C program using fork() that creates a parent and child process and displays their PID, PPID, and process states. The process state transitions are observed using ps, top, and /proc.

## Objectives

1. Create a child process using fork().
2. Display PID and PPID of parent and child.
3. Demonstrate Running, Waiting, and Terminated states.
4. Observe process information using ps.
5. Inspect process information using /proc.
6. Monitor processes using top.

## Process Creation

The parent process creates a child using fork(). After fork(), both processes continue execution independently.

## Process State Transitions

### Parent Process

Running -> Waiting -> Running -> Terminated

The parent enters the waiting state when it executes wait(NULL). It waits for the child to terminate.

### Child Process

Running -> Waiting/Sleeping -> Running -> Terminated

The child enters the sleeping state when sleep(10) is executed. After the sleep period, it resumes execution and then terminates.

## Linux Monitoring Commands

### ps

The ps command displays process information such as PID, PPID and process state.

Command used:

ps -o pid,ppid,state,stat,cmd -p PID

### /proc

Linux provides process information through the /proc filesystem.

Command used:

cat /proc/PID/status

Important fields include State, Pid, and PPid.

### top

The top command provides real-time information about processes, CPU usage and memory usage.

## Observation Table

| Stage | Process | State |
|------|---------|-------|
| Before fork | Parent | Running |
| After fork | Parent | Running |
| After fork | Child | Running |
| During sleep() | Child | Waiting/Sleeping |
| During wait() | Parent | Waiting |
| After child exits | Parent | Running |
| After completion | Child | Terminated |
| End of program | Parent | Terminated |

## Result

The program successfully demonstrated parent-child process creation using fork() and process-state transitions. The ps, top and /proc tools were used to monitor the processes and verify their PID, PPID and states.
