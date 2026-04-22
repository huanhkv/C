#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "linked_list.h"

struct Queue {
    int len;
    struct Node *top;
    struct Node *bot;
} Queue;

struct PopQueueOutput {
    int value;
    int status;
} PopQueueOutput;

struct Queue* initQueue() {
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->len = 0;
    queue->top = NULL;
    queue->bot = NULL;
    return queue;
}

void printQueue(struct Queue queue) {

    printf("Queue have %d elements: [", queue.len);
    struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp = queue.top;
    while (tmp != NULL) {
        printf("%d, ", tmp->value);
        tmp = tmp->pNext;
    }
    printf("]\n");

}

bool isQueueEmpty(struct Queue queue) {
    if (queue.len == 0)
        return 1;
    return 0;
}

void freeQueue(struct Queue *queue) {
    struct Node *tmp;
    while (queue->top != NULL) {
        tmp = queue->top;
        queue->top = queue->top->pNext;
        free(tmp);
    }
    free(queue);
}

struct PopQueueOutput popQueue(struct Queue *queue) {

    struct PopQueueOutput response;

    if (isQueueEmpty(*queue)) {
        printf("Queue is empty\n");
        response.value = 0;
        response.status = -1;
        return response;
    }
    response.value = queue->top->value;
    response.status = 0;

    queue->top = queue->top->pNext;
    queue->len--;

    return response;
}

void pushQueue(struct Queue *queue, int value) {

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->value = value;
    newNode->pNext = NULL;

    if (queue->bot == NULL) {
        queue->bot = newNode;
        queue->top = newNode;
    } else {
        queue->bot->pNext = newNode;
        queue->bot = queue->bot->pNext;
    }
    queue->len++;
}

