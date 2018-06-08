import random
import time
def merge(a,b):
		c=[]
		while len(a) and len(b):
			if a[0]<b[0]:
				c.append(a.pop(0))
			else:
				c.append(b.pop(0))
		if len(a) == 0:
			c+=b
		if len(b) == 0:
			c+=a
		return c
    
def merge_sort(arr):
	if len(arr)==0 or len(arr)==1 :
		return arr
	mid=int((0+len(arr))/2)
	a=merge_sort(arr[:mid])
	b=merge_sort(arr[mid:])
	c=merge(a,b)
	return c
L=[]
for i in range(1000):
	L.append(random.randint(0,1001))
print "Unsorted array is",L
start=time.clock()
L=merge_sort(L)
end=time.clock()
print "Sorted array is",L
print "time taken",(end-start)
