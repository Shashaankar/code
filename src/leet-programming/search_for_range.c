/**
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    
    if (!nums || numsSize <=0) {
        return NULL;
    }
    
    int left,right,mid,index,start_index,end_index,i;
    int *ret_array = NULL;
    left = 0;
    right = numsSize-1;
    index=-1;
    start_index = end_index = -1;
    
    while (left <= right) {
        
        mid = left+ (right-left)/2;
        
        if (nums[mid] == target) {
            index = mid;
            break;
        }
        
        if (target > nums[mid]) {
            left = mid+1;
        } else {
            right = mid-1;
        }
        
    } // while
    
    if (index != -1) {
        
        start_index = end_index = index;
        
        for (i=index-1; (i >=0) && (target==nums[i]); i--) {
            start_index = i;
        }       
        
        for (i=index+1; (i<numsSize) && (target==nums[i]); i++) {
            end_index = i;
        }
    }
    
    *returnSize = 2;
    ret_array = malloc(2 * sizeof(int));
    
    ret_array[0] = start_index;
    ret_array[1] = end_index;
    
    return ret_array;
    
}
