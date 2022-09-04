#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Stack{
	int top;
	unsigned capacity;
	int* array;
};

struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}


int isFull(struct Stack* stack){
	//when top of stack is equal to size - 1
	return stack->top == stack->capacity - 1; //if top == capicity - 1 // top = 4 & capacity = 5 - 1
}

int isEmpty(struct Stack* stack){
	return stack->top == -1;
}

void push(struct Stack* stack){
	if(isFull(stack)){
		printf("\nStack is full..");
	}
	else{
		int e;
		printf("\nEnter element : ");
		scanf("%d", &e);
		stack->top++;
		stack->array[stack->top] = e;
		printf("\n%d pushed succefully!", e);
	}
}

void pop(struct Stack* stack){
	if(isEmpty(stack)){
		printf("\nStack is Empty!");
	}
	else{
		printf("\nElement poped successfully!");
		stack->array[stack->top--];
	}
}

void peek(struct Stack* stack){
	if(isEmpty(stack)){
		printf("\nStack is Empty!");
	}
	else{
		printf("\nTop of the stack : %d", stack->array[stack->top]);
	}
}

void traverse(struct Stack* stack){
	if(isEmpty(stack)){
		printf("\nStack is Empty!");
	}
	else{
		int i;
		for(i = stack->top; i > -1; i--){
			printf("\n%d", stack->array[i]);
		}
	}
}

int main(){
	unsigned n;
	printf("\nEnter the size of stack : ");
	scanf("%d", &n);
	struct Stack* stack = createStack(n);
	int ch;
	while(1){
		printf("\n\n1. Push element\n2. Pop element\n3. Peek element\n4. Travers Stack\n5. Exit");
		printf("\nEnter choice : ");
		scanf("%d", &ch);
		switch(ch){
			case 1:
				push(stack);
				break;
			case 2:
				pop(stack);
				break;
			case 3:
				peek(stack);
				break;
			case 4:
				traverse(stack);
				break;
			case 5:
				printf("\nTerminated successfully!");
				exit(0);
		}
	}
	return 0;
}
