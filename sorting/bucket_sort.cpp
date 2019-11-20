// Bucket Sort in C++ programming
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void bucketSort(float *array, int size)
{
    vector<float> bucket[size];
    for (int i = 0; i < size; i++)
    {
        bucket[int(array[i]) * 10].push_back(array[i]);
    }
    for (int i = 0; i < size; i++)
    {
        sort(bucket[i].begin(), bucket[i].end());
    }
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        while (!bucket[i].empty())
        {
            array[index++] = *(bucket[i].begin());
            bucket[i].erase(bucket[i].begin());
        }
    }
}
void printArray(float *array, int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}
int main()
{
    float data[] = {.42, .32, .33, .52, .37, .47, .51};
    int size = sizeof(data) / sizeof(data[0]);
    bucketSort(data, size);
    cout << "Sorted array in ascending order: \n";
    printArray(data, size);
}