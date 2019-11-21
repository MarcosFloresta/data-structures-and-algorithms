# Python3 program for implementation of Shell Sort
def shell_sort(array, n):
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = array[i]
            j = i
            while j >= gap and array[j - gap] > temp:
                array[j] = array[j - gap]
                j -= gap
            array[j] = temp
        gap //= 2


data = [9, 8, 3, 7, 5, 6, 4, 1]
size = len(data)
shell_sort(data, size)
print('Sorted Array in Ascending Order:')
print(data)