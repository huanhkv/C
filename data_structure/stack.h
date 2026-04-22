#ifndef STACK_H
#define STACK_H

#include<stdbool.h>

struct Stack {
    int len;
    struct Node *top;
};

struct PopStackOutput {
    int value;
    int status;
};

struct Stack* initStack() ;
void printStack(struct Stack stack);
bool isStackEmpty(struct Stack stack);
void freeStack(struct Node *head);
struct PopStackOutput popStack(struct Stack *stack);
void pushStack(struct Stack *stack, int value);

#endif
