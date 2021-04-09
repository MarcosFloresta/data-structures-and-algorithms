# Linked List Operations: Traverse, Insert and Delete

In this tutorial, you will learn different operations on a linked list. Also, you will find implementation of linked list operations in C/C++, Python and Java.

Now that you have got an understanding of the basic concepts behind linked list and their types, it's time to dive into the common operations that can be performed.

Two important points to remember:

* `head` points to the first node of the linked list
* `next` pointer of the last node is `NULL`, so if the next current node is `NULL`, we have reached the end of the linked list.

In all of the examples, we will assume that the linked list has three nodes `1 --->2 --->3` with node structure as below:

```cpp
struct node
{
  int data;
  struct node *next;
};
```

## Traverse a Linked List

Displaying the contents of a linked list is very simple. We keep moving the temp node to the next one and display its contents.

When `temp` is `NULL`, we know that we have reached the end of the linked list so we get out of the while loop.

```cpp
struct node *temp = head;
printf("\n\nList elements are - \n");
while(temp != NULL)
{
     printf("%d --->",temp->data);
     temp = temp->next;
}
```

The output of this program will be:

```
List elements are - 
1 --->2 --->3 --->
```

## Insert Elements to a Linked List

You can add elements to either the beginning, middle or end of the linked list.

### 1. Insert at the beginning
   
* Allocate memory for new node
* Store data
* Change next of new node to point to head
* Change head to point to recently created node

```c
struct node *newNode;
newNode = malloc(sizeof(struct node));
newNode->data = 4;
newNode->next = head;
head = newNode;
```
### 2. Insert at the End

* Allocate memory for new node
* Store data
* Traverse to last node
* Change next of last node to recently created node
  
```c
struct node *newNode;
newNode = malloc(sizeof(struct node));
newNode->data = 4;
newNode->next = NULL;

struct node *temp = head;
while(temp->next != NULL){
  temp = temp->next;
}

temp->next = newNode;
```

### 3. Insert at the Middle

* Allocate memory and store data for new node
* Traverse to node just before the required position of new node
* Change next pointers to include new node in between

```c
struct node *newNode;
newNode = malloc(sizeof(struct node));
newNode->data = 4;

struct node *temp = head;

for(int i=2; i < position; i++) {
    if(temp->next != NULL) {
        temp = temp->next;
    }
}
newNode->next = temp->next;
temp->next = newNode;
```

### Delete from a Linked List

You can delete either from the beginning, end or from a particular position.

### 1. Delete from beginning

* Point head to the second node

```c
head = head->next;
```

### 2. Delete from end

* Traverse to second last element
* Change its next pointer to null

```c
struct node* temp = head;
while(temp->next->next!=NULL){
  temp = temp->next;
}
temp->next = NULL;
```

### 3. Delete from middle

* Traverse to element before the element to be deleted
* Change next pointers to exclude the node from the chain

```c
for(int i=2; i< position; i++) {
    if(temp->next!=NULL) {
        temp = temp->next;
    }
}

temp->next = temp->next->next;
```

## LinkedList Operations in Python, Java, C, and C++

### Python

```python
# Linked list operations in Python


# Create a node
class Node:
    def __init__(self, item):
        self.item = item
        self.next = None


class LinkedList:

    def __init__(self):
        self.head = None

    # Insert at the beginning
    def insertAtBeginning(self, data):
        new_node = Node(data)

        new_node.next = self.head
        self.head = new_node

    # Insert after a node
    def insertAfter(self, node, data):

        if node is None:
            print("The given previous node must inLinkedList.")
            return

        new_node = Node(data)
        new_node.next = node.next
        node.next = new_node

    # Insert at the end
    def insertAtEnd(self, data):
        new_node = Node(data)

        if self.head is None:
            self.head = new_node
            return

        last = self.head
        while (last.next):
            last = last.next

        last.next = new_node

    # Deleting a node
    def deleteNode(self, position):

        if self.head == None:
            return

        temp_node = self.head

        if position == 0:
            self.head = temp_node.next
            temp_node = None
            return

        # Find the key to be deleted
        for i in range(position - 1):
            temp_node = temp_node.next
            if temp_node is None:
                break

        # If the key is not present
        if temp_node is None:
            return

        if temp_node.next is None:
            return

        next = temp_node.next.next
        temp_node.next = None
        temp_node.next = next

    def printList(self):
        temp_node = self.head
        while (temp_node):
            print(str(temp_node.item) + " ", end="")
            temp_node = temp_node.next


if __name__ == '__main__':

    llist = LinkedList()
    llist.insertAtEnd(1)
    llist.insertAtBeginning(2)
    llist.insertAtBeginning(3)
    llist.insertAtEnd(4)
    llist.insertAfter(llist.head.next, 5)

    print('Linked list:')
    llist.printList()

    print("\nAfter deleting an element:")
    llist.deleteNode(3)
    llist.printList()
```

### Java

```java
// Linked list operations in Java

class LinkedList {
  Node head;

  // Create a node
  class Node {
    int item;
    Node next;

    Node(int d) {
      item = d;
      next = null;
    }
  }

  public void insertAtBeginning(int data) {
    // insert the item
    Node new_node = new Node(data);
    new_node.next = head;
    head = new_node;
  }

  public void insertAfter(Node prev_node, int data) {
    if (prev_node == null) {
      System.out.println("The given previous node cannot be null");
      return;
    }
    Node new_node = new Node(data);
    new_node.next = prev_node.next;
    prev_node.next = new_node;
  }

  public void insertAtEnd(int data) {
    Node new_node = new Node(data);

    if (head == null) {
      head = new Node(data);
      return;
    }

    new_node.next = null;

    Node last = head;
    while (last.next != null)
      last = last.next;

    last.next = new_node;
    return;
  }

  void deleteNode(int position) {
    if (head == null)
      return;

    Node node = head;

    if (position == 0) {
      head = node.next;
      return;
    }
    // Find the key to be deleted
    for (int i = 0; node != null && i < position - 1; i++)
      node = node.next;

    // If the key is not present
    if (node == null || node.next == null)
      return;

    // Remove the node
    Node next = node.next.next;

    node.next = next;
  }

  public void printList() {
    Node node = head;
    while (node != null) {
      System.out.print(node.item + " ");
      node = node.next;
    }
  }

  public static void main(String[] args) {
    LinkedList llist = new LinkedList();

    llist.insertAtEnd(1);
    llist.insertAtBeginning(2);
    llist.insertAtBeginning(3);
    llist.insertAtEnd(4);
    llist.insertAfter(llist.head.next, 5);

    System.out.println("Linked list: ");
    llist.printList();

    System.out.println("\nAfter deleting an element: ");
    llist.deleteNode(3);
    llist.printList();
  }
}
```

### C

```c
// Linked list operations in C

#include <stdio.h>
#include <stdlib.h>

// Create a node
struct Node {
  int item;
  struct Node* next;
};

void insertAtBeginning(struct Node** ref, int data) {
  // Allocate memory to a node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

  // insert the item
  new_node->item = data;
  new_node->next = (*ref);

  // Move head to new node
  (*ref) = new_node;
}

// Insert a node after a node
void insertAfter(struct Node* node, int data) {
  if (node == NULL) {
    printf("the given previous node cannot be NULL");
    return;
  }

  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->item = data;
  new_node->next = node->next;
  node->next = new_node;
}

void insertAtEnd(struct Node** ref, int data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node* last = *ref;

  new_node->item = data;
  new_node->next = NULL;

  if (*ref == NULL) {
    *ref = new_node;
    return;
  }

  while (last->next != NULL)
    last = last->next;

  last->next = new_node;
  return;
}

void deleteNode(struct Node** ref, int key) {
  struct Node *temp = *ref, *prev;

  if (temp != NULL && temp->item == key) {
    *ref = temp->next;
    free(temp);
    return;
  }
  // Find the key to be deleted
  while (temp != NULL && temp->item != key) {
    prev = temp;
    temp = temp->next;
  }

  // If the key is not present
  if (temp == NULL) return;

  // Remove the node
  prev->next = temp->next;

  free(temp);
}

// Print the linked list
void printList(struct Node* node) {
  while (node != NULL) {
    printf(" %d ", node->item);
    node = node->next;
  }
}

// Driver program
int main() {
  struct Node* head = NULL;

  insertAtEnd(&head, 1);
  insertAtBeginning(&head, 2);
  insertAtBeginning(&head, 3);
  insertAtEnd(&head, 4);
  insertAfter(head->next, 5);

  printf("Linked list: ");
  printList(head);

  printf("\nAfter deleting an element: ");
  deleteNode(&head, 3);
  printList(head);
}
```

### C++

```cpp
// Linked list operations in C++

#include <stdlib.h>
#include <iostream>

using namespace std;

// Create a node
struct Node {
  int item;
  struct Node* next;
};

void insertAtBeginning(struct Node** ref, int data) {

  // Allocate memory to a node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

  // insert the item
  new_node->item = data;
  new_node->next = (*ref);

  // Move head to new node
  (*ref) = new_node;
}

// Insert a node after a node
void insertAfter(struct Node* prev_node, int data) {
  if (prev_node == NULL) {
    cout << "the given previous node cannot be NULL";
    return;
  }

  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->item = data;
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}

void insertAtEnd(struct Node** ref, int data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node* last = *ref;

  new_node->item = data;
  new_node->next = NULL;

  if (*ref == NULL) {
    *ref = new_node;
    return;
  }

  while (last->next != NULL)
    last = last->next;

  last->next = new_node;
  return;
}

void deleteNode(struct Node** ref, int key) {
  struct Node *temp = *ref, *prev;

  if (temp != NULL && temp->item == key) {
    *ref = temp->next;
    free(temp);
    return;
  }
  // Find the key to be deleted
  while (temp != NULL && temp->item != key) {
    prev = temp;
    temp = temp->next;
  }

  // If the key is not present
  if (temp == NULL) return;

  // Remove the node
  prev->next = temp->next;

  free(temp);
}

// Print the linked list
void printList(struct Node* node) {
  while (node != NULL) {
    cout << node->item << " ";
    node = node->next;
  }
}

// Driver program
int main() {
  struct Node* head = NULL;

  insertAtEnd(&head, 1);
  insertAtBeginning(&head, 2);
  insertAtBeginning(&head, 3);
  insertAtEnd(&head, 4);
  insertAfter(head->next, 5);

  cout << "Linked list: ";
  printList(head);

  cout << "\nAfter deleting an element: ";
  deleteNode(&head, 3);
  printList(head);
}
```