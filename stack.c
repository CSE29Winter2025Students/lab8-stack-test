#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void push(int num){
	struct Node* newNode = malloc(sizeof(struct Node));
       	newNode->data = num;	
	newNode->next = stackTop;
	stackTop = newNode;	
}


int pop(){
	struct Node * temp = stackTop;
	stackTop = stackTop->next;

	int toReturn = temp->data;
	free(temp);
	return toReturn;
}

int main(){

	push(10);
	printf("%d\n", pop());
	

	for(int i = 0; i < 29; i++){
			
		push(i);		
	}

	for(int i = 0; i < 29; i++){
		printf("i = %d, pop() = %d\n", i, pop());
	}
	return 0;
}
