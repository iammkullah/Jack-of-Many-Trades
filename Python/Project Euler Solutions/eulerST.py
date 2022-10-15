
# Calculating the sum of digits present in the number
def sum_digits(x):
    sum=0
    for i in str(x):
        sum = sum + int(i)
    return sum