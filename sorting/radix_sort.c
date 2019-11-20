/*
radixSort(array)
  d <- maximum number of digits in the largest element
  create d buckets of size 0-9
  for i <- 0 to d
    sort the elements according to ith place digits using countingSort

countingSort(array, d)
  max <- find largest element among dth place elements
  initialize count array with all zeros
  for j <- 0 to size
    find the total count of each unique digit in dth place of elements and
    store the count at jth index in count array
  for i <- 1 to max
    find the cumulative sum and store it in count array itself
  for j <- size down to 1
    restore the elements to array
    decrease count of each element restored by 1
*/

// Radix Sort in C Programming
#include <stdio.h>
int getMax(int array[], int n)
{
    int max = array[0];
    for (int i = 1; i < n; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}
void countingSort(int array[], int size, int place)
{
    int output[size + 1];
    int max = (array[0] / place) % 10;
    for (int i = 1; i < size; i++)
    {
        if (((array[i] / place) % 10) > max)
            max = array[i];
    }
    int count[max + 1];
    for (int i = 0; i < max; ++i)
        count[i] = 0;
    for (int i = 0; i < size; i++)
        count[(array[i] / place) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }
    for (int i = 0; i < size; i++)
        array[i] = output[i];
}
void radixsort(int array[], int size)
{
    int max = getMax(array, size);
    for (int place = 1; max / place > 0; place *= 10)
        countingSort(array, size, place);
}
void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
}
int main()
{
    int array[] = {121, 432, 564, 23, 1, 45, 788};
    int n = sizeof(array) / sizeof(array[0]);
    radixsort(array, n);
    printArray(array, n);
}