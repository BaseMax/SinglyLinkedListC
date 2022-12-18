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
void deleteAtIndex(SinglyLinkedList *singlyLinkedList, int index) {
    if (index < 0 || index >= singlyLinkedList->size) {
        printf("Index out of range: %d\\n", index);
        return;
    }
    // If index is 0, delete the first node
    if (index == 0) {
        deleteFirstNode(singlyLinkedList);
        return;
    }
    // If index is equal to the size of the list, delete the last node
    else if (index == singlyLinkedList->size - 1) {
        deleteLastNode(singlyLinkedList);
        return;
    }
    // Otherwise, delete the node at the given index
    Node *temp = singlyLinkedList->head;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }
    Node *toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
    singlyLinkedList->size--;
}

/**
 * @brief Print the list
 * 
 * @param singlyLinkedList 
 */
void printList(SinglyLinkedList *singlyLinkedList) {
    if (singlyLinkedList->head == NULL) {
        printf("List is empty\\n");
        return;
    }
    Node *temp = singlyLinkedList->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\\n");
}

/**
 * @brief Print the list in reverse order
 * 
 * @param singlyLinkedList 
 */
void printListReverse(SinglyLinkedList *singlyLinkedList) {
    if (singlyLinkedList->head == NULL) {
        printf("List is empty\\n");
        return;
    }
    Node *temp = singlyLinkedList->head;
    int *arr = (int *) malloc(singlyLinkedList->size * sizeof(int));
    int i = 0;
    while (temp != NULL) {
        arr[i++] = temp->data;
        temp = temp->next;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d ", arr[j]);
    }
    printf("\\n");
    free(arr);
}

/**
 * @brief Reverse the list
 * 
 * @param singlyLinkedList 
 */
void reverseList(SinglyLinkedList *singlyLinkedList) {
    if (singlyLinkedList->head == NULL) {
        printf("List is empty\\n");
        return;
    }
    Node *prev = NULL;
    Node *current = singlyLinkedList->head;
    Node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    singlyLinkedList->tail = singlyLinkedList->head;
    singlyLinkedList->head = prev;
}

/**
 * @brief Free the list
 * 
 * @param singlyLinkedList 
 */
void freeList(SinglyLinkedList *singlyLinkedList) {
    if (singlyLinkedList->head == NULL) {
        printf("List is empty\\n");
        return;
    }
    Node *temp = singlyLinkedList->head;
    while (temp != NULL) {
        Node *toDelete = temp;
        temp = temp->next;
        free(toDelete);
    }
    singlyLinkedList->head = NULL;
    singlyLinkedList->tail = NULL;
    singlyLinkedList->size = 0;
}

int main() {
    // Create a new list
    SinglyLinkedList *singlyLinkedList = createList();

    // Insert at the beginning
    insertAtBeginning(singlyLinkedList, 1);
    insertAtBeginning(singlyLinkedList, 2);
    insertAtBeginning(singlyLinkedList, 3);
    insertAtBeginning(singlyLinkedList, 4);
    insertAtBeginning(singlyLinkedList, 5);

    // Print the list
    printList(singlyLinkedList);

    // Insert at the end
    insertAtEnd(singlyLinkedList, 6);
    insertAtEnd(singlyLinkedList, 7);
    insertAtEnd(singlyLinkedList, 8);

    // Print the list
    printList(singlyLinkedList);

    // Insert at the given index
    insertAtIndex(singlyLinkedList, 9, 0);
    insertAtIndex(singlyLinkedList, 10, 5);
    insertAtIndex(singlyLinkedList, 11, 9);
    
    // Print the list
    printList(singlyLinkedList);

    // Delete the first node
    deleteFirstNode(singlyLinkedList);

    // Print the list
    printList(singlyLinkedList);

    // Delete the last node
    deleteLastNode(singlyLinkedList);

    // Print the list
    printList(singlyLinkedList);
    
}