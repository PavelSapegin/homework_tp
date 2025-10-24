
arr = [1,2,3,4,5,6]
def heap(arr,n,root):
    large = root
    left = 2*root + 1
    right = 2*root + 2
    
    if left < n and arr[left] > arr[large]:
        large = left
        
    if right < n and arr[right] > arr[large]:
        large = right
        
    if large != root:
        arr[large],arr[root] = arr[root],arr[large]
        heap(arr,n,large)     
    

def heap_sort(arr):
    
    for root in range(len(arr),-1,-1):
        heap(arr,len(arr),root)
        
    for i in range(len(arr)-1,-1,-1):
        arr[i],arr[0] = arr[0],arr[i]
        heap(arr,i,0)
    
    
heap_sort(arr)
print(arr)
