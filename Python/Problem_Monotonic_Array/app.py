#############################################################################################################
## Problem: We are given a array and we have to decide wether it is monotonic or not. It is monotonic if it
##          is continuosly increasing or decreasing.
##          
## Explanation: So our strategy is to use two pointer algo. First pointer at the first index and second pointer
##              at the second index. We will check the trend between these two entries that wether the array is
##              increasing or decreasing. Firslty we will use the check_starting_duplicates function to get the
##              trend for the starting indicies. Afterwards we will just check this trend in entire array. If not found 
##              simply return False.
###############################################################################################################


def monotonic_array(array):
    first_pointer = check_starting_duplicates(array)
    second_pointer = first_pointer + 1
    if(array[first_pointer] < array[second_pointer]):
        first_pointer += 1
        second_pointer += 1
        while(second_pointer != len(array)):
            if array[first_pointer] > array[second_pointer]:
                return False
            elif array[first_pointer] <= array[second_pointer]:
                first_pointer += 1
                second_pointer += 1
    elif(array[first_pointer] > array[second_pointer]):
        first_pointer += 1
        second_pointer += 1
        while(second_pointer != len(array)):
            if array[first_pointer] < array[second_pointer]:
                return False
            elif array[first_pointer] >= array[second_pointer]:
                first_pointer += 1
                second_pointer += 1
                
    return True
        







def check_starting_duplicates(array):  #This function is used if we have starting values which are not giving us the correct trend.
    first_pointer = 0
    second_pointer = 1
    while(second_pointer != len(array)):
        print(array[first_pointer],array[second_pointer])
        if(array[first_pointer] != array[second_pointer]):
            return first_pointer
        else:
            first_pointer += 1
            second_pointer += 1
    return False
array = [-1,-1,-10,-1100, -1100,-1101,-1102,-9001]

a = monotonic_array(array)
print(a)



###########################################################################################################
## Time Complexity: O(n) 
## Space COmplextiy: O(1) as we are giving answer only in terms of True or False.
###########################################################################################################