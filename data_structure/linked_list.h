#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node* initList(int value);
struct Node* insertNode(struct Node *head, int value);
struct Node* appendNode(struct Node *oldHead, int value);
struct Node* deleteNode(struct Node *head, int index);

void printList(struct Node *head);
void freeList(struct Node *head);

int lenList(struct Node *head);

#endif
