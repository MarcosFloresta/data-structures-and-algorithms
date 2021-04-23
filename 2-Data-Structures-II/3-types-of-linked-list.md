# Types of Linked List - Singly linked, doubly linked and circular

In this tutorial, you will learn different types of linked list. Also, you will find implementation of linked list in C.

Before you learn about the type of the linked list, make sure you know about the LinkedList Data Structure.

There are three common types of Linked List.

1. Singly Linked List
2. Doubly Linked List
3. Circular Linked List

## Singly Linked List

It is the most common. Each node has data and a pointer to the next node.

![Singly linked list](/2-Data-Structures-II/img/linked-list-concept_0.webp)

Node is represented as:

```c
struct node {
    int data;
    struct node *next;
}
```

A three-member singly linked list can be created as:

```c
/* Initialize nodes */
struct node *head;
struct node *one = NULL;
struct node *two = NULL;
struct node *three = NULL;

/* Allocate memory */
one = malloc(sizeof(struct node));
two = malloc(sizeof(struct node));
three = malloc(sizeof(struct node));

/* Assign data values */
one->data = 1;
two->data = 2;
three->data = 3;

/* Connect nodes */
one->next = two;
two->next = three;
three->next = NULL;

/* Save address of first node in head */
head = one;
```

## Doubly Linked List

We add a pointer to the previous node in a doubly-linked list. Thus, we can go in either direction: forward or backward.

![Doubly linked list](/2-Data-Structures-II/img/doubly-linked-list-concept.webp)

A node is represented as

```c
struct node {
    int data;
    struct node *next;
    struct node *prev;
}
```

A three-member doubly linked list can be created as

```c
/* Initialize nodes */
struct node *head;
struct node *one = NULL;
struct node *two = NULL;
struct node *three = NULL;

/* Allocate memory */
one = malloc(sizeof(struct node));
two = malloc(sizeof(struct node));
three = malloc(sizeof(struct node));

/* Assign data values */
one->data = 1;
two->data = 2;
three->data = 3;

/* Connect nodes */
one->next = two;
one->prev = NULL;

two->next = three;
two->prev = one;

three->next = NULL;
three->prev = two;

/* Save address of first node in head */
head = one;
```

## Circular Linked List

A circular linked list is a variation of a linked list in which the last element is linked to the first element. This forms a circular loop.

![Circular linked list](/2-Data-Structures-II/img/circular-linked-list.webp)

A circular linked list can be either singly linked or doubly linked.

* for singly linked list, next pointer of last item points to the first item
* In the doubly linked list, prev pointer of the first item points to the last item as well.

A three-member circular singly linked list can be created as:

```c
/* Initialize nodes */
struct node *head;
struct node *one = NULL;
struct node *two = NULL;
struct node *three = NULL;

/* Allocate memory */
one = malloc(sizeof(struct node));
two = malloc(sizeof(struct node));
three = malloc(sizeof(struct node));

/* Assign data values */
one->data = 1;
two->data = 2;
three->data = 3;

/* Connect nodes */
one->next = two;
two->next = three;
three->next = one;

/* Save address of first node in head */
head = one;
```