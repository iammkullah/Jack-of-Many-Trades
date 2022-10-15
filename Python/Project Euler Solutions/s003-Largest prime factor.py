# Solution to Project Euler problem 3
# Copyright (c) Swarup Tripathy. All rights reserved.

# The prime factors of 13195 are 5, 7, 13 and 29.
# What is the largest prime factor of the number 600851475143 ?

# div=[]

# def primefactors(n):
#     # for i in range(2,n):
#     #     for j in range(2,n):
#     #         if i%j==0:
#     #             div.append(i)
#     # print(div)
#     div = [i for i in range(2,n) for j in range(2,n) if i%j==0]

#     # for k in range(len(div)):
#     #     if div.count(div[k]) >1:
#     #         None
#     #     else:
#     #         pf.append(div[k])

#     pf=[div[k] for k in range(len(div)) if div.count(div[k])==1]
#     return pf

# def largestPrimeFactor(n):
#     # lg=[]
#     # for i in range(2,n):
#     #     if n%i==0:
#     #         if i in primefactors(n):
#     #             lg.append(i)
#     # print(lg)

#     lg = [i for i in range(2,n) if n%i==0 if i in primefactors(n)]
#     print(max(lg))

# largestPrimeFactor(13195)

# --------------------------------------------------------------------------------------

from eulerlib import primes
import math

def largestPrimeFactor(n):
    
    # for j in range(2,n):
    #     if n%j==0:
    #         list.append(j)
    list = [j for j in range(2,int(math.sqrt(n))) if n%j==0]
    
    # for i in range(len(list)):
    #     if list[i] in primes(n//2):
    #         final.append(list[i])
    final=[list[i] for i in range(len(list)) if list[i] in primes(int(math.sqrt(n)))]
    print(max(final))

largestPrimeFactor(13195)
largestPrimeFactor(600851475143)