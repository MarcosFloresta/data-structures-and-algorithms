# Python Program To Sort data in ascending order using bubble sort.
def bubbleSort(array):
    for i in range(len(array)):
        swapped = True
        for j in range(0, len(array) - i - 1):
            # To sort in descending order, change > to < in this line.
            if array[j] > array[j + 1]:
                (array[j], array[j + 1]) = (array[j + 1], array[j])
                swapped = False
                if swapped == True:
                    break


data = [-2, 45, 0, 11, -9]
bubbleSort(data)
print('Sorted Array in Ascending Order:')
print(data)
