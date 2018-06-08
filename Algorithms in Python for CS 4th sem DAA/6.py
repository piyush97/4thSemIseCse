import random
import time
def merge(a,b):
		m=[]
		c=0
		while len(a) and len(b):
			if a[0]<b[0]:
			    m.append(a.pop(0))
			else:
			    c+=len(a)
			    m.append(b.pop(0))
		if len(a) == 0:
			m+=b
		if len(b) == 0:
			m+=a
		return m,c

def sort(arr):
        if len(arr) <= 1:
                return arr,0
        mid = len(arr)//2
        b,r1 = sort(arr[:mid])
        c,r2 = sort(arr[mid:])
        d,c = merge(b,c)
        return d,(r1+r2+c)
n=int(input("Enter range of numbers: "))
x=[]
for i in range(n):
     x.append(random.randint(0,100))
print "Initial list: ",x
start= time.clock()
s,c= sort(x)
end= time.clock()
print "Sorted list: ",s
print "Number of Invertions: ",c
print "Time :",end-start
