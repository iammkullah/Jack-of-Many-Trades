x = int(input("Enter number of elements: "))
x += 1
k = int(input("Enter k "))
k -= 1
a = k 
l = list(range(1,x))
b = 0
while (len(l) != 1):
    l.pop(k)
    k = (k+a)%len(l)    
print(l[0])