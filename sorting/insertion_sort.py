# Insertion sort in Python
def insertion_sort(array):
    for step in range(1, len(array)):
        key = array[step]
        j = step - 1
        while j >= 0 and key < array[j]:
            # For descending order, change key<array[j] to key>array[j].
            array[j + 1] = array[j]
            j = j - 1
        array[j + 1] = key
data = [9, 5, 1, 4, 3]
insertion_sort(data)
print('Sorted Array in Ascending Order:')
print(data)