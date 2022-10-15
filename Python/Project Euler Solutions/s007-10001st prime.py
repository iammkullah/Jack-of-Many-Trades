# By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
# What is the 10001st prime number?

from eulerlib import primes     # this will print primes up to the defined number

n=100001
while n>0:
    if len(primes(n))==10001:
        print(primes(n)[-1])
        break
    else:
        n += 1
    


# print(len(primes(10001)))
# print(primes(10001)[-1])