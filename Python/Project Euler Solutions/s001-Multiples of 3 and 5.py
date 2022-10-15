# Solution to Project Euler problem 1
# Copyright (c) Swarup Tripathy. All rights reserved.

# If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
# Find the sum of all the multiples of 3 or 5 below 1000.


n = 1000
sum = 0
flag = 0
for i in range(1000):
    if(i%3==0 or i%5==0):
        sum = sum + i
    else:
        flag+=1

print(sum)

