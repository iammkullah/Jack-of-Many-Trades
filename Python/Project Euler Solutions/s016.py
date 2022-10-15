# 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
# What is the sum of the digits of the number 2^1000?

import timeit
import math

start = timeit.default_timer()

def sum_digits(x):
    sum=0
    for i in str(x):
        sum = sum + int(i)
    return sum

if __name__ == "__main__":
    # pow = int(input("Enter the required power:"))     # uncomment the below two lines if you wish to take input from the user
    # a = int(math.pow(2,pow))
    a = int(math.pow(2,1000))
    print(sum_digits(a))

end = timeit.default_timer()

print("time taken to run the program:",end-start)