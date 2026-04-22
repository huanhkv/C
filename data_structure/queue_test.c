#include<stdio.h>
#include "stack.h"

int main() {
    struct Queue *queue = initQueue();

    printQueue(*queue);

    if (isQueueEmpty(*queue))
        printf("Queue is EMPTY");
    else
        printf("Queue is NOT EMPTY");

    for (int i=1; i<5; i++) {
        pushQueue(queue, i);
        printQueue(*queue);
    }

    printQueue(*queue);
    printf("%d\n", isQueueEmpty(*queue));

    struct PopQueueOutput value;
    for(int i=1; i<10; i++) {
        value = popQueue(queue);
        if (value.status ==-1)
            break;
        printf("Pop value: %d\n", value.value);
        printQueue(*queue);
    }

    return 0;
}
