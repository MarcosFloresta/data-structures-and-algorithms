# Selection sort in Python
def selection_sort(array, size):
    for step in range(size):
        min_idx = step
        for i in range(step + 1, size):
            # To sort in descending order, change > to < in this line.
            if array[i] < array[min_idx]:
                min_idx = i
        (array[step], array[min_idx]) = (array[min_idx], array[step])


data = [-2, 45, 0, 11, -9]
size = len(data)
selection_sort(data, size)
print('Sorted Array in Ascending Order:\n')
print(data)
