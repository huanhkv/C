#include<stdio.h>
#include "stack.h"

int main() {
    struct Stack *stack = initStack();

    printStack(*stack);

    printf("%d\n", isStackEmpty(*stack));

    for (int i=1; i<5; i++) {
        pushStack(stack, i);
        printStack(*stack);
    }

    printStack(*stack);
    printf("%d\n", isStackEmpty(*stack));

    struct PopStackOutput value;
    for(int i=1; i<10; i++) {
        value = popStack(stack);
        if (value.status ==-1)
            break;
        printf("Pop value: %d\n", value.value);
    }

    return 0;
}
