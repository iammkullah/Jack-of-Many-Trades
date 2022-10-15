'''
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
'''

# * pip install num2words - library for the conversion of whole numbers to their text form.

from num2words import num2words
# import timeit

# start = timeit.default_timer()

def letters_used(x):
    sum = 0 
    for i in range(1,x+1):
        word = num2words(i)
        # print(word)
        for l in word:

            if l in 'abcdefghijklmnopqrstuvwxyz':
                sum = sum + len(l)
    print(sum)

if __name__ == "__main__":
    letters_used(1000)

# end = timeit.default_timer()

# print("time taken by the program:",end-start)