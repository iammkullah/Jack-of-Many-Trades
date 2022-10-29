## This program will print all the prime numbers of your given range 

#this method check whether number is prime or not
def isprime(n):
    flag=1
    for i in range(2,n):
        if n%i==0:
            flag=0
    return flag

#this method print the prime number of your given range
def isprimeness(noofprimeness):
    number=2
    count =0
    while count <noofprimeness:
        if isprime(number):
            count+=1
            print(number)
        number+=1   
noofprimeness=int(input("How many prime numbers do you want to print? : "))
isprimeness(noofprimeness)
