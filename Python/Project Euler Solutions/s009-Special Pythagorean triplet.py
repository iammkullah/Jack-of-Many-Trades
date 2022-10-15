# A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
# a^2 + b^2 = c^2
# For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
# There exists exactly one Pythagorean triplet for which a + b + c = 1000.
# Find the product abc.

'''
The question can be interpreted as any natural number and not as adjacent natural numbers
- a to vary from 1 to 1000
    - b to vary from a to 1000
        - c to vary from b to 1000
            - if statemtent to check sum == 1000
                - if true - check a**2 + b**2 == c**2
                    - if true - print the values and the a*b*c and then exit from the program
'''
import timeit

start = timeit.default_timer()


for a in range(1,1000):
    for b in range(a,1000):
        for c in range(b,1000):
            if a+b+c==1000:
                if a**2 + b**2 == c**2:
                    print('a=',a,'b=',b,'c=',c)
                    print(a*b*c)
                    stop = timeit.default_timer()
                    print('Time: ', stop - start) 
                    exit()
                    
 
