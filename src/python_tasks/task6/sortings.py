def quick_sort(arr):
    
    if len(arr) <= 1:
        return arr
    
    pred = arr[0]
    left = [x for x in arr[1:] if x <= pred]
    right = [x for x in arr[1:] if x > pred]

    return quick_sort(left) + [pred] + quick_sort(right)

def bubble_sort(arr):
    for i in range(len(arr)):
        for j in range(len(arr)):
            if arr[i] > arr[j]:
                arr[i],arr[j] = arr[j],arr[i]
                
    return arr

def insert_sort(arr):
    if len(arr) <= 1:
        return arr
    
    for i in range(len(arr)):
        while  i > 0 and arr[i] < arr[i-1]:
            arr[i],arr[i-1] = arr[i-1],arr[i]
            i -= 1
            
            if i == 0:
                break
        
    
    return arr
