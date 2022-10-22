#############################################################################################################
## Problem: We are given a array and we have to move all the target numbers to end.
##          
## Explanation: So our strategy is to use two pointer algo. Is to use two pointer one at the index of the target
##              number and other at the index next to target number. We will be swapping the two numbers untill
##              of them reaches at the end.
###############################################################################################################


def move_to_last(array,target):
    
    len_array = len(array) 
    for index,num in enumerate(array):
        if (num == target):
            first_pointer= index
            second_pointer = index + 1
            while(second_pointer !=len_array):
                swap = array[first_pointer] 
                array[first_pointer] = array[second_pointer]
                array[second_pointer] = swap
                first_pointer +=1
                second_pointer +=1
                print(array)
        


array = [2,1,5,2,8,2,4,9]
target = 2
move_to_last(array,target)


###########################################################################################################
## Time Complexity: O(n2) 
## Space COmplextiy: O(1) as we are manipulating the original array.
###########################################################################################################