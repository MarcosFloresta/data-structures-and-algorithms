# Bubble sort in Python
def bubble_sort(array):
    for i in range(len(array)):
        for j in range(0, len(array) - i - 1):
            # To sort in descending order, change > to < in this line.
            if array[j] > array[j + 1]:
                (array[j], array[j + 1]) = (array[j + 1], array[j])


data = [-2, 45, 0, 11, -9]
bubble_sort(data)
print('Sorted Array in Ascending Order:')
print(data)
