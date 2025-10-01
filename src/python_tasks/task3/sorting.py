def quicksort(arr):
    
    if len(arr) <= 1:
        return arr
    
    pred = arr[0]
    left = [x for x in arr[1:] if x <= pred]
    right = [x for x in arr[1:] if x > pred]

    return quicksort(left) + [pred] + quicksort(right)


