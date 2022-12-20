# Singly Linked-List C

This is a simple implementation of a singly linked-list in C. Singly linked-lists are a type of data structure that are used to store a collection of elements. Each element in a singly linked-list is called a node. Each node contains two parts: the data and a pointer to the next node. The first node in a singly linked-list is called the head. The last node in a singly linked-list is called the tail. The tail node points to NULL. The head node is the only node that can be accessed from outside the linked-list. The head node is used to traverse the linked-list. The head node is also used to add and remove nodes from the linked-list.

## Structure

**Types:**

```c
typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct SinglyLinkedList {
    Node *head;
    Node *tail;
    int size;
} SinglyLinkedList;
```

**Methods:**

- `Node *createNode(int data)`: Create a new node with the given data and return a pointer to the node.
- `SinglyLinkedList *createSinglyLinkedList()`: Create a new singly linked list
- `void insertAtEnd(SinglyLinkedList* singlyLinkedList, int data)`: Insert a new node at the end of the list
- `void insertAtBeginning(SinglyLinkedList* singlyLinkedList, int data)`: Insert a new node at the beginning of the list
- `void insertAtIndex(SinglyLinkedList* singlyLinkedList, int data, int index)`: Insert a new node at the given index
- `void deleteFirstNode(SinglyLinkedList* singlyLinkedList)`: Delete the first node of the list
- `void deleteLastNode(SinglyLinkedList* singlyLinkedList)`: Delete the last node of the list
- `void deleteAtIndex(SinglyLinkedList* singlyLinkedList, int index)`: Delete the node at the given index
- `void printList(SinglyLinkedList* singlyLinkedList)`: Print the list
- `void printListReverse(SinglyLinkedList* singlyLinkedList)`: Print the list in reverse order
- `void reverseList(SinglyLinkedList* singlyLinkedList)`: Reverse the list
- `void reverseListRecursive(SinglyLinkedList* singlyLinkedList)`: Reverse the list recursively
- `Node* findMiddleNode(SinglyLinkedList* singlyLinkedList)`: Find the middle node of the list
- `Node* findMiddleNodeRecursive(SinglyLinkedList* singlyLinkedList)`: Find the middle node of the list recursively
- `Node* findMin(SinglyLinkedList* singlyLinkedList)`: Find the minimum element in the list
- `Node* findMax(SinglyLinkedList* singlyLinkedList)`: Find the maximum element in the list
- `Node* findNthNodeFromEnd(SinglyLinkedList* singlyLinkedList, int n)`: Find the nth node from the end of the list
- `Node* findNthNodeFromBeginning(SinglyLinkedList* singlyLinkedList, int n)`: Find the nth node from the beginning of the list
- `Node* findNthNodeFromBeginningRecursive(SinglyLinkedList* singlyLinkedList, int n)`: Find the nth node from the beginning of the list recursively
- `Node* findNthNodeFromEndRecursive(SinglyLinkedList* singlyLinkedList, int n)`: Find the nth node from the end of the list recursively
- `void removeDuplicates(SinglyLinkedList* singlyLinkedList)`: Remove dubplicates from the list
- `void sortList(SinglyLinkedList* singlyLinkedList)`: Sort the list (ascending) using bubble sort algorithm O(n^2)
- `void freeList(SinglyLinkedList* singlyLinkedList)`: Free the list

## Usage

```c
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
```

## License

This project is licensed under the GPL-3.0 License - see the [LICENSE](LICENSE) file for details.

Copyright (c) 2022, Max Base
