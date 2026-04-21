#include<stdio.h>
#include<stdlib.h>

struct Node {
    int value;
    struct Node *pNext;
} Node;


struct Node* initList(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->pNext = NULL;
    return newNode;
}

void freeList(struct Node *head) {
    struct Node *temp;
    while (head->pNext != NULL) {
        temp = head;
        head = head->pNext;
        free(temp);
    }
}

int lenList(struct Node *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->pNext;
    }
    return count - 1;
}

void printList(struct Node *head) {
    printf("Print Linked list: [");

    while (head->pNext != NULL) {
        printf("%d, ", head->value);
        head = head->pNext;
    }
    printf("]\n");
}

struct Node* insertNode(struct Node *head, int value) {

    // Find last node
    struct Node *last = head;
    while (last->pNext != NULL)
        last = last->pNext;

    // Create new node
    struct Node *childNode = (struct Node*)malloc(sizeof(struct Node));
    childNode->value = value;
    childNode->pNext = NULL;

    // Insert at the last of linded list
    last->pNext = childNode;

    return head;
}

struct Node* appendNode(struct Node *oldHead, int value) {

    // Create new node
    struct Node *newHead = (struct Node*)malloc(sizeof(struct Node));
    newHead->value = value;
    newHead->pNext = oldHead;

    return newHead;
}

// Delete Node from a linked list
struct Node* deleteNode(struct Node *head, int index) {

    if (index<0) {
        perror("Index must not negative number");
        abort();
    }
        
    if (index==0) {
        struct Node *tmp = head->pNext;
        free(head);
        return tmp;
    }

    struct Node *cur = head;
    for (int i=0; cur && i < index - 1; i++)
        cur = cur->pNext;
    
    if (!cur || !cur->pNext) {
        printf("Index out of range\n");
        abort();
    }


    struct Node *toDelete = cur->pNext;
    if (toDelete!=NULL)
        cur->pNext = toDelete->pNext;

    free(toDelete);

    return head;
}
