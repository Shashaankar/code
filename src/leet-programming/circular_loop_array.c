/**
You are given an array of positive and negative integers. If a number n at an index is positive, 
then move forward n steps. Conversely, if it's negative (-n), move backward n steps. 
Assume the first element of the array is forward next to the last element, and the last element 
is backward next to the first element. Determine if there is a loop in this array. 
A loop starts and ends at a particular index with more than 1 element along the loop. The loop must be "forward" or "backward'.

Example 1: Given the array [2, -1, 1, 2, 2], there is a loop, from index 0 -> 2 -> 3 -> 0.

Example 2: Given the array [-1, 2], there is no loop.

Note: The given array is guaranteed to contain no element "0".

Can you do it in O(n) time complexity and O(1) space complexity?
**/


int checkLoop(int *nums, int index, int size)
{
    int i,steps,flag,count,wrap;
    
    flag=0;
    count=0;
    wrap=0;
    for (i = index; i<size && i>=0; ) {
        
        //printf("index = %d\n", i);
        if (i == index && flag == 0) {
            flag=1;
        } else if(i == index && flag == 1) {
            flag = 2;
            break;
        }
        
        count++;
        if (count > size) {
            // looping at other values
            break;
        }
        
        
        steps = nums[i];
        if (i+steps >= size) {
            wrap = 1;
        }
        i = (i+steps) % size;
        
        
        
    } // for
    
    //printf("count = %d, flag = %d, index = %d\n", count, flag, index);
    if (flag == 2 && count > 1 && wrap) {
        return 1;
    }
    
    return 0;
}



bool circularArrayLoop(int* nums, int numsSize) {
    
    int i;
    
    if (!nums || numsSize <= 1) {
        
        return 0;
    }
    
    
    for (i=0; i<numsSize; i++) {
        
        if (checkLoop(nums, i, numsSize)) {
            return 1;
        }
            
    }
    
    return 0;
    
}


