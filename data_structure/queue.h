#ifndef QUEUE_H
#define QUEUE_H

#include<stdbool.h>

struct Queue {
    int len;
    struct Node *top;
    struct Node *bot;
};

struct PopQueueOutput {
    int value;
    int status;
};

struct Queue* initQueue();
void printQueue(struct Queue queue);
bool isQueueEmpty(struct Queue queue);
void freeQueue(struct Queue *queue);
struct PopQueueOutput popQueue(struct Queue *queue);
void pushQueue(struct Queue *queue, int value);

#endif
