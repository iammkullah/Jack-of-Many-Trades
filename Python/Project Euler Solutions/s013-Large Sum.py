import timeit

start = timeit.default_timer()

file = open('C:/Users/iwill/Desktop/github/0-Python Agai/Pyrup/00-Project Euler Problems/s013','r')        # ksjffljsk is the file name where i have pasted the entire digits
listLines = file.readlines()        # reading all the lines 
totalSum = sum(int(i) for i in listLines)       # summing up all the individual 50 digit numbers
print(totalSum)                     
print(str(totalSum)[:10])           # since 'int' object is not subscriptable so we convert it to string and print the first 10 digits of the sum
  
stop = timeit.default_timer()
print('Time:',stop-start)
