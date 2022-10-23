# Josephus Problem - In a circle there are certain number of people standing, at k intervals the person present will be killed, people will be killed till only one os them is remaining. Write an algorithm that can find out the index of the person that will stay alive.  

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