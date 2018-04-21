/**
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
**/
#define MAX(_a, _b) ((_a)>(_b)?(_a):(_b))

int maxSubArray(int* nums, int numsSize) {
    
    if (nums == NULL || numsSize <=0) {
        return 0;
    }
    
    int i,max,sum;
    max = sum = nums[0];
    
    for (i=1; i<numsSize; i++) {
        sum = MAX(sum+nums[i], nums[i]);
        max = MAX(sum, max);
    }
    
    
    return max;
    
}
