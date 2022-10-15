# The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
# Find the sum of all the primes below two million.
from eulerlib import primes

def sumPrimes(n):
    result = sum(primes(n))
    print(result)

sumPrimes(2000000)