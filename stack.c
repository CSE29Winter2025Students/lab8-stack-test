#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct Node *stackTop;

int empty() { return stackTop == NULL; }
void reset() {
    while (!empty())
        pop();
}

// Implement your team's function here!

void push(int i) {
    struct Node *new = malloc(sizeof(struct Node));
    new->data = i;
    new->next = stackTop;
    stackTop = new;
}
