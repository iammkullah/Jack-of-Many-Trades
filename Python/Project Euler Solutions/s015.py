# Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down,
# there are exactly 6 routes to the bottom right corner.
# How many such routes are there through a 20×20 grid?

'''
____________ REFERENCES ____________

- https://www.robertdickau.com/lattices.html - (Lattice path and catalan)
- https://brilliant.org/wiki/catalan-numbers/ - (Catalan numbers )

'''


# s = int(input('enter an integer: '))

import timeit
start = timeit.default_timer()
s = 20
n = s+1

def total_paths(n):
    total_paths = 0
    list_2 = [x for x in range(1, n+1)]
    final_list = [1]
    sum = 1
    for j in range(n-2):
        # print('\nlist 2:', list_2)

        for i in range(1, n+1):
            try:
                # print(list_2[i])
                sum = sum + list_2[i]
                final_list.append(sum)
            except:
                0
        sum = 1
        list_2 = [1]
        list_2 = [x for x in final_list]
         
        # print(final_list)
        total_paths = final_list[-1]
        final_list=[1]
    
    print(total_paths)

total_paths(n)

end = timeit.default_timer()
print('Total time taken by the program:',end-start)