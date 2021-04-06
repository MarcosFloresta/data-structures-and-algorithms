# Types of Queues

In this tutorial, you will learn different types of queues with along with illustration.

A queue is a useful data structure in programming. It is similar to the ticket queue outside a cinema hall, where the first person entering the queue is the first person who gets the ticket.

There are four different types of queues:

* Simple Queue
* Circular Queue
* Priority Queue
* Double Ended Queue

## Simple Queue

In a simple queue, insertion takes place at the rear and removal occurs at the front. It strictly follows the FIFO (First in First out) rule.

![Simple Queue Representation](/1-Data-Structures-I/img/queue/simple-queue_0.webp)

To learn more, visit Queue Data Structure.

## Circular Queue

In a circular queue, the last element points to the first element making a circular link.

![Circular Queue Representation](/1-Data-Structures-I/img/queue/circular-queue.webp)

The main advantage of a circular queue over a simple queue is better memory utilization. If the last position is full and the first position is empty, we can insert an element in the first position. This action is not possible in a simple queue.

To learn more, visit Circular Queue Data Structure.

## Priority Queue

A priority queue is a special type of queue in which each element is associated with a priority and is served according to its priority. If elements with the same priority occur, they are served according to their order in the queue.

![Priority Queue Representation](/1-Data-Structures-I/img/queue/priority-queue.webp)

Insertion occurs based on the arrival of the values and removal occurs based on priority.

To learn more, visit Priority Queue Data Structure.

## Deque (Double Ended Queue)

In a double ended queue, insertion and removal of elements can be performed from either from the front or rear. Thus, it does not follow the FIFO (First In First Out) rule.

![Deque Representation](/1-Data-Structures-I/img/queue/double-ended-queue.webp)

To learn more, visit Deque Data Structure.