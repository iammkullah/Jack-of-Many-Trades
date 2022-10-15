# Solution to Project Euler problem 4
# Copyright (c) Swarup Tripathy. All rights reserved.

# 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
# What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

# Evenly divisible - doesn't leave a remainder

def highestMultiple(a):
    # mul=1
    # for k in range(1,21):
    # mul = mul*k
    mul=1
    for k in range(1,a+1):
        mul = mul*k
    return mul


def smallestMultiple(x):
    
    list = [l for l in range(1,x+1)]
    i=0
    while i<highestMultiple(x):
        commonMult = 210        # divisible by 2,3,5,7
        if x==0:
            return 0
        elif x<=7:
            if x==6:
                return highestMultiple(5)
            elif x==7:
                return highestMultiple(5)*7
            else:
                return highestMultiple(x)
        else:
            # i=0
            i = i + commonMult
            final=[]
            for j in range(len(list)):
                if i%list[j]==0:
                    final.append(i)
                else:
                    continue
                
            if len(final)==x:
                return final[1]
        
def testCode():
    for k in range(20):
        print(smallestMultiple(k),end=" ")

testCode()

    
    
    
        