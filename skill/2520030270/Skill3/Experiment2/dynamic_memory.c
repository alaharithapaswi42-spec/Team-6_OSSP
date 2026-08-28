#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 10

typedef struct Node {
    int data;
    struct Node *next;
} Node;

int main() {
    int capacity = INITIAL_SIZE;
    int count = 0;
    char *buffer;
    Node *head = NULL;
    Node *temp;

    /* Dynamically allocate buffer */
    buffer = malloc(capacity * sizeof(char));

    if (buffer == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Dynamic Memory Management Demo\n");

    /* Dynamically store input */
    printf("Enter a string: ");
    fgets(buffer, capacity, stdin);

    buffer[strcspn(buffer, "\n")] = '\0';

    /* Resize buffer when required */
    count = strlen(buffer);

    if (count >= capacity - 1) {
        capacity *= 2;

        char *new_buffer = realloc(buffer,
                                   capacity * sizeof(char));

        if (new_buffer == NULL) {
            printf("Memory reallocation failed.\n");
            free(buffer);
            return 1;
        }

        buffer = new_buffer;
    }

    printf("Stored string: %s\n", buffer);

    /* Create linked list */
    for (int i = 1; i <= 5; i++) {
        Node *newNode = malloc(sizeof(Node));

        if (newNode == NULL) {
            printf("Node allocation failed.\n");
            free(buffer);
            return 1;
        }

        newNode->data = i * 10;
        newNode->next = head;
        head = newNode;
    }

    printf("Linked List: ");

    temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");

    /* Release linked-list memory */
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    /* Release buffer memory */
    free(buffer);

    printf("All dynamically allocated memory released.\n");

    return 0;
}
