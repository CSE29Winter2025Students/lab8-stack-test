#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct Node *stackTop;

int empty() { return stackTop == NULL; }
void reset() {
    while (!empty())
        pop();
}

void push(int num) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = stackTop;
    stackTop = newNode;
}

int pop() {
    struct Node *temp = stackTop;
    stackTop = stackTop->next;

    int toReturn = temp->data;
    free(temp);
    return toReturn;
}

void copy_to_array(int *array, size_t space) {
    struct Node *current_node = stackTop;
    for (size_t i = 0; i < space && current_node != NULL; ++i) {
        array[i] = current_node->data;
        current_node = current_node->next;
    }
}

static int test_main() {

    push(10);
    printf("%d\n", pop());

    for (int i = 0; i < 29; i++) {
        push(i);
    }

    int array[29];
    copy_to_array(array, 29);

    for (int i = 0; i < 29; i++) {
        printf("i = %d, pop() = %d\n", i, pop());
    }

    printf("The array contains: ");
    for (int i = 0; i < 29; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
