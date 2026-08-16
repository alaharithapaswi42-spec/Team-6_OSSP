# Experiment 1 - Process Creation and Linux OS Resource Investigation

## Aim

To develop a C program that demonstrates how Linux executes a command entered by a user using fork(), exec(), and wait(), and to investigate the relationship between hardware resources and operating system services.

## Objectives

1. Accept a Linux command as input.
2. Create a child process using fork().
3. Execute the command using exec().
4. Make the parent wait using wait().
5. Display the PID of the parent and child processes.
6. Investigate CPU, storage, and process information using Linux commands.

## Program

The program accepts a Linux command from the user. The parent process creates a child using fork(). The child executes the command using execlp(). The parent waits for the child using wait().

## Important System Calls

### fork()

Creates a new child process.

### execlp()

Replaces the child process with the requested Linux command.

### wait()

Makes the parent process wait until the child process terminates.

### getpid()

Returns the PID of the current process.

### getppid()

Returns the PID of the parent process.

## Linux Commands Used

### uname

Displays Linux kernel and system information.

### lscpu

Displays CPU architecture, processor count, cores, threads, and related CPU information.

### lsblk

Displays block storage devices and partitions.

### ps

Displays information about currently running processes.

### top

Provides real-time information about running processes and CPU/memory usage.

## OS Abstraction

### CPU

The operating system abstracts the physical CPU and provides processes with CPU execution time through scheduling. Programs do not directly control the physical processor.

### Memory

The operating system provides each process with a virtual address space. Programs use virtual memory addresses while Linux manages the underlying physical memory.

### Storage

Linux provides files and directories as an abstraction over physical storage devices. Commands such as lsblk expose the underlying block devices.

### I/O Devices

Linux provides device drivers and standard interfaces so applications can communicate with hardware without directly controlling the hardware.

### Processes

Linux represents running programs as processes. Each process has a PID and is managed by the operating system scheduler and process-management subsystem.

## Observation

The parent process creates a child process using fork(). The child receives its own PID and executes the requested command using execlp(). The parent waits for the child using wait(). After the child terminates, the parent continues execution.

## Result

The program successfully demonstrates Linux process creation, command execution using exec(), parent-child synchronization using wait(), and basic investigation of hardware resources and operating system services.
