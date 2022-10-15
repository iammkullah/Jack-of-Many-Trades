# The following iterative sequence is defined for the set of positive integers:

# n → n/2 (n is even)
# n → 3n + 1 (n is odd)

# Using the rule above and starting with 13, we generate the following sequence:

# 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
# It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

# Which starting number, under one million, produces the longest chain?

# NOTE: Once the chain starts the terms are allowed to go above one million.

import timeit

start = timeit.default_timer()

i=13
dictionary = {}
while i<1000000:
    
    list=[i]
    j=i
    
    while j>1:
        if j%2==0:
            j = j//2
            list.append(j)
            # print(list)
        else:
            j = 3*j+1
            list.append(j)
            # print(list)
    # print(i,'len is',len(list))
    dictionary[i] = len(list)
    i = i+1
# print(dictionary)
max_value = max(dictionary, key = dictionary.get)
print('starting number:',max_value)

end = timeit.default_timer()
print(end-start)

'''
i=13
i<14:
    - list=[13]
    - 13>1:
        - i = 40
        - list = [13,40]
    - 40>1:
        - i = 20
        - list = [13,40,20]
'''