/**
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
**/

int search(int* nums, int numsSize, int target) {
    
    if (!nums || numsSize <=0) {
        return -1;
    }
    
    int left, mid, right;
    
    left = 0;
    right = numsSize-1;
    
    while (left <= right) {
        
        mid = left + (right-left)/2;
        if (nums[mid] == target) {
            return mid;
        }
        printf("mid=%d, nums[mid]:=%d, left=%d, right=%d\n", mid, nums[mid], left, right);
    if (nums[left] <= nums[mid])
    {
        /* As this subarray is sorted, we can quickly
           check if key lies in half or other half */
        if (target >= nums[left] && target <= nums[mid]) {
           right = mid-1;
           continue;
        }
        
        left = mid+1;
        continue;
    }
 
    /* If arr[l..mid] is not sorted, then arr[mid... r]
       must be sorted*/
    if (target >= nums[mid] && target <= nums[right]) {
        left = mid+1;
        continue;
    }
        
    right = mid-1;
        
    } // while
    
    
    return -1;
    
}
