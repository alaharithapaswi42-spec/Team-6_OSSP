SKILL WEEK 3 - EXPERIMENT 2

Title:
To Allocate Buffers Dynamically, Resize Arrays, Prevent Buffer Overflow, Manage Linked Lists, Release Memory Correctly, Verify with Valgrind.

Objective:
To demonstrate dynamic memory allocation and proper memory management in C.

Program:
dynamic_memory.c

Description:
The program demonstrates:
1. Dynamic allocation using malloc().
2. Resizing dynamically allocated memory using realloc().
3. Safe input handling with a fixed buffer limit.
4. Creation and management of a linked list.
5. Dynamic allocation of linked-list nodes.
6. Releasing linked-list nodes using free().
7. Releasing the dynamically allocated buffer.
8. Verification of memory management using Valgrind.

Compilation:

gcc -Wall -Wextra dynamic_memory.c -o dynamic_memory

Execution:

./dynamic_memory

Valgrind Verification:

valgrind --leak-check=full ./dynamic_memory

Expected Result:
The program successfully allocates and manages dynamic memory, creates a linked list, releases allocated memory correctly, and should report no memory leaks when checked using Valgrind.
