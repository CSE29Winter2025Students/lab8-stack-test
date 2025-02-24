#ifndef STACK_H
#define STACK_H

struct Node {
	int data;
	struct Node * next;
};

struct Node * stackTop;
void push (int num);
int pop();


#endif
