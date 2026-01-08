def heap(arr, n, root):  # построение кучи, где n - размер кучи, root - корень
    large = root
    left = 2 * root + 1
    right = 2 * root + 2

    if left < n and arr[left] > arr[large]:
        large = left

    if right < n and arr[right] > arr[large]:
        large = right

    if large != root:
        arr[large], arr[root] = arr[root], arr[large]
        heap(arr, n, large)


def heap_sort(arr):

    for root in range(len(arr), -1, -1):  # построение max-heap
        heap(arr, len(arr), root)

    # выносим элементы из сортировки и повторяем для оставшихся
    for i in range(len(arr) - 1, -1, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heap(arr, i, 0)


    return arr
if __name__ == '__main__':
    arr = [6,5,4,3,2,1]
    arr = heap_sort(arr)
    print(arr)
