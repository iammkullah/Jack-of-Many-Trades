'''
By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

    3
   7 4
  2 4 6
 8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:

index v
0                              75
1                            95 64
2                          17 47 82
3                        18 35 87 10
4                      20 04 82 47 65
5                    19 01 23 75 03 34
6                  88 02 77 73 07 63 67
7                99 65 04 28 06 16 70 92
8              41 41 26 56 83 40 80 70 33
9            41 48 72 33 47 32 37 16 94 29
10          53 71 44 65 25 43 91 52 97 51 14
11        70 11 33 28 77 73 17 78 39 68 17 57
12      91 71 52 38 17 14 91 43 58 50 27 29 48
13    63 66 04 68 89 53 67 30 73 16 69 87 40 31
14  04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. 
However, Problem 67, is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, 
and requires a clever method! ;o)
'''
import time

start = time.time()

file = open('C:/Users/iwill/Desktop/github/0-Python Again/Pyrup/00-Project Euler Problems/Solutions/s018','r')

list = []
for i in file.readlines():
    list.append(i.split())

# Converting the elements of sublists into strings

final = [[75]]
l = []
for j in list[1:]:
    for k in j:
        l.append(int(k))
    final.append(l)
    l=[]

def compute():
    print('length of final list:',len(final))
    for a in reversed(range(len(final)-1)):
        # print(len(final[a]))
        for b in range(len(final[a])):
            
            final[a][b] = final[a][b] + max(final[a+1][b],final[a+1][b+1])

    print(final[0][0])
if __name__ == "__main__":
    compute()

end = time.time()
print('time taken: ',end-start)

'''
len(final) = 15
a = 13,12,11,10,9,8,7,6,5,4,3,2,1,0
- a = 13
- b = 14 = len(63 66 04 68 89 53 67 30 73 16 69 87 40 31)
    - final[13][14] = final[13][14] + max(final[14][14],final[14][15])
'''