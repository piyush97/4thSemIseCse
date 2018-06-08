import random
import time
def partition(arr,low,high):
    i = ( low-1 )
    pivot = arr[high]
    for j in range(low , high):
        if   arr[j] <= pivot:
                     i = i+1;arr[i],arr[j] = arr[j],arr[i]
    arr[i+1],arr[high] = arr[high],arr[i+1]
    return ( i+1 )
    
def quickSort(arr,low,high):
    if low < high:
        pi = partition(arr,low,high)
        quickSort(arr, low, pi-1)
        quickSort(arr, pi+1, high)
arr =[]
n=10
for i in range(n):
    arr.append(random.randint(0,100))
print arr
start=time.clock()
quickSort(arr,0,n-1)
end=time.clock()
print arr
print "Time taken to sort array: ", end-start,"seconds"
