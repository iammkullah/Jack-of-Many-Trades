#############################################################################################################
## Problem: We are given a array and we have to move all the target numbers to end.
##          
## Explanation: So our strategy is to use two pointer algo. One pointer is at the starting index and the second
##              is at the end of the array. We will be swapping the two numbers untill the first pointer is
##              equal to the second pointer.  
###############################################################################################################


def move_to_last(array,target):
    first_pointer = 0
    second_pointer = len(array) -1
    while(first_pointer != second_pointer):
        if(array[second_pointer] == target):  #If the starting step first index and last index both contains target num.
            second_pointer -=1
        elif(array[first_pointer] == target):
            swap = array[first_pointer] 
            array[first_pointer] = array[second_pointer]
            array[second_pointer] = swap
            first_pointer +=1
            second_pointer -=1
        first_pointer += 1
        print(array)
        


array = [2,1,5,2,8,2,4,2]
target = 2
move_to_last(array,target)


###########################################################################################################
## Time Complexity: O(n) 
## Space COmplextiy: O(1) as we are manipulating the original array.
###########################################################################################################