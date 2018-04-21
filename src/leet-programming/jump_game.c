/**
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
**/

bool canJump(int* nums, int numsSize) {
    
    int i,jump,temp,gap;
    
    if (nums == NULL || numsSize <= 0) {
        return 0;
    }
    
    
    i = jump = temp = 0;
    
    if (numsSize <= 1) {
        return 1;
    }
    jump = nums[0];
    
    while (i < numsSize) {
        
 
        if (nums[i] == 0 && jump <= i) {
            
            return 0;
        }
        
        // Get the max jump from current index
        temp = i + nums[i];
        
        if (temp > jump) {
            jump = temp;
        }
        
        // Base conditions
        if (jump >= numsSize-1) {
          return 1;
        }
        
        i++;
    }
    
    return 0;
}






