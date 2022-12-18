/**
 * 
 * @file SinglyLinkedList.c
 * @author Max Base (maxbasecode@gmail.com)
 * @brief Singly Linked List Implementation in C
 * @version 0.1
 * @date 2022-12-18
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct SinglyLinkedList {
    Node *head;
    Node *tail;
    int size;
} SinglyLinkedList;

/**
 * @brief Create a new node
 * 
 * @param data
 * @return Node* 
 */
Node *createNode(int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/**
 * @brief Create a new singly linked list
 * 
 * @return SinglyLinkedList* 
 */
SinglyLinkedList *createSinglyLinkedList() {
    SinglyLinkedList *newSinglyLinkedList = (SinglyLinkedList *) malloc(sizeof(SinglyLinkedList));
    newSinglyLinkedList->head = NULL;
    newSinglyLinkedList->tail = NULL;
    newSinglyLinkedList->size = 0;
    return newSinglyLinkedList;
}

/**
 * @brief Insert a new node at the end of the list
 * 
 * @param singlyLinkedList 
 * @param data 
 */
void insertAtEnd(SinglyLinkedList *singlyLinkedList, int data) {
    Node *newNode = createNode(data);
    if (singlyLinkedList->head == NULL) {
        singlyLinkedList->head = newNode;
        singlyLinkedList->tail = newNode;
    } else {
        singlyLinkedList->tail->next = newNode;
        singlyLinkedList->tail = newNode;
    }
    singlyLinkedList->size++;
}

/**
 * @brief Insert a new node at the beginning of the list
 * 
 * @param singlyLinkedList 
 * @param data 
 */
void insertAtBeginning(SinglyLinkedList *singlyLinkedList, int data) {
    Node *newNode = createNode(data);
    if (singlyLinkedList->head == NULL) {
        singlyLinkedList->head = newNode;
        singlyLinkedList->tail = newNode;
    } else {
        newNode->next = singlyLinkedList->head;
        singlyLinkedList->head = newNode;
    }
    singlyLinkedList->size++;
}

/**
 * @brief Insert a new node at the given index
 * 
 * @param singlyLinkedList 
 * @param data 
 * @param index 
 */
void insertAtIndex(SinglyLinkedList *singlyLinkedList, int data, int index) {
    if (index < 0 || index > singlyLinkedList->size) {
        printf("Index out of range: %d\\n", index);
        return;
    }

    // If index is 0, insert at the beginning
    if (index == 0) {
        insertAtBeginning(singlyLinkedList, data);
        return;
    }
    // If index is equal to the size of the list, insert at the end
    else if (index == singlyLinkedList->size) {
        insertAtEnd(singlyLinkedList, data);
        return;
    }
    // Otherwise, Insert at the given index
    Node *newNode = createNode(data);
    Node *temp = singlyLinkedList->head;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    singlyLinkedList->size++;
}

/**
 * @brief Delete the first node of the list
 * 
 * @param singlyLinkedList 
 */
void deleteFirstNode(SinglyLinkedList *singlyLinkedList) {
    if (singlyLinkedList->head == NULL) {
        printf("List is empty\\n");
        return;
    }
    Node *temp = singlyLinkedList->head;
    singlyLinkedList->head = singlyLinkedList->head->next;
    free(temp);
    singlyLinkedList->size--;
}

/**
 * @brief Delete the last node of the list
 * 
 * @param singlyLinkedList 
 */
void deleteLastNode(SinglyLinkedList *singlyLinkedList) {
    if (singlyLinkedList->head == NULL) {
        printf("List is empty\\n");
        return;
    }
    Node *temp = singlyLinkedList->head;
    while (temp->next != singlyLinkedList->tail) {
        temp = temp->next;
    }
    free(singlyLinkedList->tail);
    temp->next = NULL;
    singlyLinkedList->tail = temp;
    singlyLinkedList->size--;
}

/**
 * @brief Delete the node at the given index
 * 
 * @param singlyLinkedList 
 * @param index 
 */
