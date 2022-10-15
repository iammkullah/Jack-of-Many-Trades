# Solution to Project Euler problem 4
# Copyright (c) Swarup Tripathy. All rights reserved.

# A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
# Find the largest palindrome made from the product of two 3-digit numbers.

def isPalindrome(x):
    n = str(x)
    forward = []
    for i in range(len(n)):
        forward.append(n[i])
    
    rev = forward[::-1]     # using slicing technique to return reversed list
    
    if forward==rev:
        return True 
    else:
        return False

list=[]
for i in range(100,1000):
    for j in range(100,1000):
        result = i*j
        if isPalindrome(result):
            list.append(result)
        else:
            None

print(max(list))

# print(isPalindrome(980009))