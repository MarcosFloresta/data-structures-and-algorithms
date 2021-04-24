# Heap Data Structure

In this tutorial, you will learn what heap data structure is. Also, you will find working examples of heap operations in C, C++, Java and Python.

Heap data structure is a complete binary tree that satisfies **the heap property**. It is also called as **a binary heap**.

A complete binary tree is a special binary tree in which

* every level, except possibly the last, is filled
* all the nodes are as far left as possible

![Complete binary tree](/2-Data-Structures-II/img/completebt_1.webp)

Heap Property is the property of a node in which

* (for max heap) key of each node is always greater than its child node/s and the key of the root node is the largest among all other nodes;
![Max-heap](/2-Data-Structures-II/img/maxheap_1.webp)
(for min heap) key of each node is always smaller than the child node/s and the key of the root node is the smallest among all other nodes.
![Min-heap](/2-Data-Structures-II/img/minheap_0.webp)

## Heap Operations

Some of the important operations performed on a heap are described below along with their algorithms.

### Heapify

Heapify is the process of creating a heap data structure from a binary tree. It is used to create a Min-Heap or a Max-Heap.

1. Let the input array be
![heap initial array](/2-Data-Structures-II/img/array_1.webp)
2. Create a complete binary tree from the array
![Complete binary tree](/2-Data-Structures-II/img/completebt-1_0.webp)
3. Start from the first index of non-leaf node whose index is given by `n/2 - 1`.
![heapify](/2-Data-Structures-II/img/start_1.webp)
4. Set current element `i` as `largest`.
5. The index of left child is given by `2i + 1` and the right child is given by `2i + 2`.
    If `leftChild` is greater than `currentElement` (i.e. element at `ith` index), set `leftChildIndex` as largest.
    If `rightChild` is greater than element in `largest`, set `rightChildIndex` as `largest`.
6. Swap largest with currentElement
![heapify](/2-Data-Structures-II/img/swap_1.webp)
7. Repeat steps 3-7 until the subtrees are also heapified.

### Algorithm

```
Heapify(array, size, i)
  set i as largest
  leftChild = 2i + 1
  rightChild = 2i + 2
  
  if leftChild &gt; array[largest]
    set leftChildIndex as largest
  if rightChild &gt; array[largest]
    set rightChildIndex as largest

  swap array[i] and array[largest]
```

To create a Max-Heap:

```
MaxHeap(array, size)
  loop from the first index of non-leaf node down to zero
    call heapif
```

For Min-Heap, both `leftChild` and `rightChild` must be smaller than the parent for all nodes.

## Insert Element into Heap

Algorithm for insertion in Max Heap

```
If there is no node, 
  create a newNode.
else (a node is already present)
  insert the newNode at the end (last node from left to right.)
  
heapify the array
```

1. Insert the new element at the end of the tree.
![insertion in heap](/2-Data-Structures-II/img/insert-heap-1.webp)
2. Heapify the tree.
![nsertion in heap](/2-Data-Structures-II/img/insert-heap-2.webp)

For Min Heap, the above algorithm is modified so that `parentNode` is always smaller than `newNode`.

## Delete Element from Heap

Algorithm for deletion in Max Heap

```
If nodeToBeDeleted is the leafNode
  remove the node
Else swap nodeToBeDeleted with the lastLeafNode
  remove noteToBeDeleted
   
heapify the array
```

1. Select the element to be deleted.
![deletion in heap](/2-Data-Structures-II/img/delete-1_1.webp)
1. Swap it with the last element.
![deletion in heap](/2-Data-Structures-II/img/delete-2_1.webp)
1. Remove the last element.
![deletion in heap](/2-Data-Structures-II/img/delete-3_0.webp)
1. Heapify the tree.
![deletion in heap](/2-Data-Structures-II/img/delete-4_0.webp)

For Min Heap, above algorithm is modified so that both `childNodes` are greater smaller than `currentNode`.

## Peek (Find max/min)

Peek operation returns the maximum element from Max Heap or minimum element from Min Heap without deleting the node.

For both Max heap and Min Heap

```c
return rootNode
``` 

## Extract-Max/Min

Extract-Max returns the node with maximum value after removing it from a Max Heap whereas Extract-Min returns the node with minimum after removing it from Min Heap.

## Python, Java, C/C++ Examples

### Python

```python
# Max-Heap data structure in Python

def heapify(arr, n, i):
    largest = i
    l = 2 * i + 1
    r = 2 * i + 2 
    
    if l < n and arr[i] < arr[l]:
        largest = l
    
    if r < n and arr[largest] < arr[r]:
        largest = r
    
    if largest != i:
        arr[i],arr[largest] = arr[largest],arr[i]
        heapify(arr, n, largest)

def insert(array, newNum):
    size = len(array)
    if size == 0:
        array.append(newNum)
    else:
        array.append(newNum);
        for i in range((size//2)-1, -1, -1):
            heapify(array, size, i)

def deleteNode(array, num):
    size = len(array)
    i = 0
    for i in range(0, size):
        if num == array[i]:
            break
        
    array[i], array[size-1] = array[size-1], array[i]

    array.remove(num)
    
    for i in range((len(array)//2)-1, -1, -1):
        heapify(array, len(array), i)
    
arr = []

insert(arr, 3)
insert(arr, 4)
insert(arr, 9)
insert(arr, 5)
insert(arr, 2)

print ("Max-Heap array: " + str(arr))

deleteNode(arr, 4)
print("After deleting an element: " + str(arr))
```

### Java

```java

// Max-Heap data structure in Java

import java.util.ArrayList;

class Heap {
  void heapify(ArrayList<Integer> hT, int i) {
    int size = hT.size();
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && hT.get(l) > hT.get(largest))
      largest = l;
    if (r < size && hT.get(r) > hT.get(largest))
      largest = r;

    if (largest != i) {
      int temp = hT.get(largest);
      hT.set(largest, hT.get(i));
      hT.set(i, temp);

      heapify(hT, largest);
    }
  }

  void insert(ArrayList<Integer> hT, int newNum) {
    int size = hT.size();
    if (size == 0) {
      hT.add(newNum);
    } else {
      hT.add(newNum);
      for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(hT, i);
      }
    }
  }

  void deleteNode(ArrayList<Integer> hT, int num)
  {
    int size = hT.size();
    int i;
    for (i = 0; i < size; i++)
    {
      if (num == hT.get(i))
        break;
    }

    int temp = hT.get(i);
    hT.set(i, hT.get(size-1));
    hT.set(size-1, temp);

    hT.remove(size-1);
    for (int j = size / 2 - 1; j >= 0; j--)
    {
      heapify(hT, j);
    }
  }

  void printArray(ArrayList<Integer> array, int size) {
    for (Integer i : array) {
      System.out.print(i + " ");
    }
    System.out.println();
  }

  public static void main(String args[]) {

    ArrayList<Integer> array = new ArrayList<Integer>();
    int size = array.size();

    Heap h = new Heap();
    h.insert(array, 3);
    h.insert(array, 4);
    h.insert(array, 9);
    h.insert(array, 5);
    h.insert(array, 2);

    System.out.println("Max-Heap array: ");
    h.printArray(array, size);

    h.deleteNode(array, 4);
    System.out.println("After deleting an element: ");
    h.printArray(array, size);
  }
}
```

### C

```c
// Max-Heap data structure in C

#include <stdio.h>
int size = 0;
void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}
void heapify(int array[], int size, int i)
{
  if (size == 1)
  {
    printf("Single element in the heap");
  }
  else
  {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] > array[largest])
      largest = l;
    if (r < size && array[r] > array[largest])
      largest = r;
    if (largest != i)
    {
      swap(&array[i], &array[largest]);
      heapify(array, size, largest);
    }
  }
}
void insert(int array[], int newNum)
{
  if (size == 0)
  {
    array[0] = newNum;
    size += 1;
  }
  else
  {
    array[size] = newNum;
    size += 1;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      heapify(array, size, i);
    }
  }
}
void deleteRoot(int array[], int num)
{
  int i;
  for (i = 0; i < size; i++)
  {
    if (num == array[i])
      break;
  }

  swap(&array[i], &array[size - 1]);
  size -= 1;
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    heapify(array, size, i);
  }
}
void printArray(int array[], int size)
{
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}
int main()
{
  int array[10];

  insert(array, 3);
  insert(array, 4);
  insert(array, 9);
  insert(array, 5);
  insert(array, 2);

  printf("Max-Heap array: ");
  printArray(array, size);

  deleteRoot(array, 4);

  printf("After deleting an element: ");

  printArray(array, size);
}
```

### C++

```cpp
// Max-Heap data structure in C++

#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}
void heapify(vector<int> &hT, int i)
{
  int size = hT.size();
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < size && hT[l] > hT[largest])
    largest = l;
  if (r < size && hT[r] > hT[largest])
    largest = r;

  if (largest != i)
  {
    swap(&hT[i], &hT[largest]);
    heapify(hT, largest);
  }
}
void insert(vector<int> &hT, int newNum)
{
  int size = hT.size();
  if (size == 0)
  {
    hT.push_back(newNum);
  }
  else
  {
    hT.push_back(newNum);
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      heapify(hT, i);
    }
  }
}
void deleteNode(vector<int> &hT, int num)
{
  int size = hT.size();
  int i;
  for (i = 0; i < size; i++)
  {
    if (num == hT[i])
      break;
  }
  swap(&hT[i], &hT[size - 1]);

  hT.pop_back();
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    heapify(hT, i);
  }
}
void printArray(vector<int> &hT)
{
  for (int i = 0; i < hT.size(); ++i)
    cout << hT[i] << " ";
  cout << "\n";
}

int main()
{
  vector<int> heapTree;

  insert(heapTree, 3);
  insert(heapTree, 4);
  insert(heapTree, 9);
  insert(heapTree, 5);
  insert(heapTree, 2);

  cout << "Max-Heap array: ";
  printArray(heapTree);

  deleteNode(heapTree, 4);

  cout << "After deleting an element: ";

  printArray(heapTree);
}
```

## Heap Data Structure Applications

* Heap is used while implementing a priority queue.
* Dijkstra’s Algorithm
* Heap Sort
