# The sum of the squares of the first ten natural numbers is, 385
# The square of the sum of the first ten natural numbers is, 3025
# Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025-285=2640.
# Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.


def sumOfSquare(n):
    sum=0
    for i in range(n+1):
        sum = sum + i**2
    return sum

def squareOfSum(x):
    sum=0
    for j in range(x+1):
        sum = sum + j
    return sum**2

def diffSquareAndSquareSum(z):
    a = squareOfSum(z)
    b = sumOfSquare(z)
    diff = a-b
    return "Square of sum = " + str(a) +" \nsum of square = " + str(b) + " \ndifference = " + str(diff)

print(diffSquareAndSquareSum(100))