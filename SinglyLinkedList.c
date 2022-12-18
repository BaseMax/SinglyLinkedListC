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
 * @param void
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
 * @param SinglyLinkedList* singlyLinkedList  
 * @param int data
 * 
 * @return void
 */
void insertAtEnd(SinglyLinkedList* singlyLinkedList, int data) {
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
 * @param SinglyLinkedList* singlyLinkedList  
 * @param int data
 * 
 * @return void
 */
void insertAtBeginning(SinglyLinkedList* singlyLinkedList, int data) {
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
 * @param SinglyLinkedList* singlyLinkedList  
 * @param int data
 * @param int index
 * 
 * @return void
 */
void insertAtIndex(SinglyLinkedList* singlyLinkedList, int data, int index) {
    if (index < 0 || index > singlyLinkedList->size) {
        printf("Index out of range: %d\n", index);
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
 * @param SinglyLinkedList* singlyLinkedList  
 * 
 * @return void
 */
void deleteFirstNode(SinglyLinkedList* singlyLinkedList) {
    if (singlyLinkedList->head == NULL) {
        printf("List is empty\n");
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
 * @param SinglyLinkedList* singlyLinkedList  
 * 
 * @return void
 */
void deleteLastNode(SinglyLinkedList* singlyLinkedList) {
    if (singlyLinkedList->head == NULL) {
        printf("List is empty\n");
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
 * @param SinglyLinkedList* singlyLinkedList  
 * @param int index
 * 
 * @return void
 */
void deleteAtIndex(SinglyLinkedList* singlyLinkedList, int index) {
    if (index < 0 || index >= singlyLinkedList->size) {
        printf("Index out of range: %d\n", index);
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
 * @param SinglyLinkedList* singlyLinkedList
 * 
 * @return void
 */
void printList(SinglyLinkedList* singlyLinkedList) {
    if (singlyLinkedList->head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *temp = singlyLinkedList->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/**
 * @brief Print the list in reverse order
 * 
 * @param SinglyLinkedList* singlyLinkedList  
 * 
 * @note This function uses an array to store the elements of the list in reverse order
 *      and then prints the array in reverse order.
 *     This is done to avoid reversing the list.
 *    This function is not efficient as it uses extra space.
 * 
 * @note To reverse the list, we can use recursion to print the list in reverse order.
 *    This function is efficient as it does not use extra space.
 *   But it is not tail recursive, so it can cause stack overflow.
 * 
 * @note To reverse the list, we can also use a stack to store the elements of the list.
 *   This function is efficient as it does not use extra space.
 * But it is not tail recursive, so it can cause stack overflow.
 * 
 */
void printListReverse(SinglyLinkedList* singlyLinkedList) {
    if (singlyLinkedList->head == NULL) {
        printf("List is empty\n");
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
    printf("\n");
    free(arr);
}

/**
 * @brief Reverse the list
 * 
 * @param SinglyLinkedList* singlyLinkedList  
 * 
 * @return void
 */
void reverseList(SinglyLinkedList* singlyLinkedList) {
    if (singlyLinkedList->head == NULL) {
        printf("List is empty\n");
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
 * @brief Reverse the list recursively
 * 
 * @param SinglyLinkedList* singlyLinkedList  
 * 
 * @return void
 */
void reverseListRecursive(SinglyLinkedList* singlyLinkedList) {
    if (singlyLinkedList->head == NULL) {
        printf("List is empty\n");
        return;
    }
    singlyLinkedList->tail = singlyLinkedList->head;
    singlyLinkedList->head = reverseListRecursiveHelper(singlyLinkedList->head);
}

/**
 * @brief Helper function for reverseListRecursive
 * 
 * @param Node* head  
 * 
 * @return Node*
 */
Node* reverseListRecursiveHelper(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node *newHead = reverseListRecursiveHelper(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

/**
 * @brief Find the middle node of the list
 * 
 * @param SinglyLinkedList* singlyLinkedList  
 * 
 * @return Node* 
 */
Node* findMiddleNode(SinglyLinkedList* singlyLinkedList) {
    if (singlyLinkedList->head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    Node *slow = singlyLinkedList->head;
    Node *fast = singlyLinkedList->head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

/**
 * @brief Find the middle node of the list recursively
 * 
 * @param SinglyLinkedList* singlyLinkedList
 * 
 * @return Node* 
 */
Node* findMiddleNodeRecursive(SinglyLinkedList* singlyLinkedList) {
    if (singlyLinkedList->head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    Node *slow = singlyLinkedList->head;
    Node *fast = singlyLinkedList->head;
    return findMiddleNodeRecursiveHelper(slow, fast);
}

/**
 * @brief Helper function for findMiddleNodeRecursive
 * 
 * @param Node* slow
 * @param Node* fast
 * 
 * @return Node* 
 */
Node* findMiddleNodeRecursiveHelper(Node* slow, Node* fast) {
    if (fast == NULL || fast->next == NULL) {
        return slow;
    }
    return findMiddleNodeRecursiveHelper(slow->next, fast->next->next);
}

/**
 * @brief Free the list
 * 
 * @param SinglyLinkedList* singlyLinkedList  
 * 
 * @return void
 */
void freeList(SinglyLinkedList* singlyLinkedList) {
    if (singlyLinkedList->head == NULL) {
        printf("List is empty\n");
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

/**
 * @brief Main entry point
 * 
 * @param int argc
 * @param char** argv
 * 
 * @return int 
 */
int main(int argc, char** argv) {
    // Create a new list
    SinglyLinkedList* singlyLinkedList = createSinglyLinkedList();

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

    // Delete the node at the given index
    deleteAtIndex(singlyLinkedList, 0);

    // Print the list
    printList(singlyLinkedList);

    // Print the list in reverse order
    printListReverse(singlyLinkedList);

    // Reverse the list
    reverseList(singlyLinkedList);

    // Print the list
    printList(singlyLinkedList);

    // Free the list
    freeList(singlyLinkedList);

    return 0;
}
