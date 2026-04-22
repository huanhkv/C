#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "linked_list.h"

struct Stack {
    int len;
    struct Node *top;
} Stack;

struct PopStackOutput {
    int value;
    int status;
} PopStackOutput;

struct Stack* initStack() {
    struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->len = 0;
    stack->top = NULL;
    return stack;
}

void printStack(struct Stack stack) {

    printf("Stack have %d elements: [", stack.len);
    struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp = stack.top;
    while (tmp != NULL) {
        printf("%d, ", tmp->value);
        tmp = tmp->pNext;
    }
    printf("]\n");

}

bool isStackEmpty(struct Stack stack) {
    if (stack.len == 0)
        return 1;
    return 0;
}

void freeStack(struct Stack *stack) {
    struct Node *tmp;
    while (stack->top != NULL) {
        tmp = stack->top;
        stack->top = stack->top->pNext;
        free(tmp);
    }
    free(stack);
}

struct PopStackOutput popStack(struct Stack *stack) {

    struct PopStackOutput response;

    if (isStackEmpty(*stack)) {
        printf("Stack is empty\n");
        response.value = 0;
        response.status = -1;
        return response;
    }
    response.value = stack->top->value;
    response.status = 0;

    stack->top = stack->top->pNext;
    stack->len--;

    return response;
}

void pushStack(struct Stack *stack, int value) {

    struct Node *newTop = (struct Node*)malloc(sizeof(struct Node));

    newTop->value = value;
    newTop->pNext = stack->top;
    stack->top = newTop;
    stack->len++;
}
