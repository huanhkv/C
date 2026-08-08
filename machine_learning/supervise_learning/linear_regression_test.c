#include<stdio.h>
#include "linked_list.h"

int main() {

    // Init
    struct Node *pLinkedList = initList(0);

    // Insert
    for (int i=1; i<10; i++)
        pLinkedList = insertNode(pLinkedList, i);
    printList(pLinkedList);
    printf("Len of list: %d\n", lenList(pLinkedList));

    // Append
    for (int i=11; i<20; i++)
        pLinkedList = appendNode(pLinkedList, i);
    printList(pLinkedList);
    printf("Len of list: %d\n", lenList(pLinkedList));

    // Delete
    deleteNode(pLinkedList, 1);
    printList(pLinkedList);
    printf("Len of list: %d\n", lenList(pLinkedList));

    deleteNode(pLinkedList, 9);
    printList(pLinkedList);
    printf("Len of list: %d\n", lenList(pLinkedList));

    freeList(pLinkedList);

    return 0;
}
