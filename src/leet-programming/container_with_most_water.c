
/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/


#define MIN(_a, _b) (_a) < (_b) ? (_a):(_b)
#define MAX(_a, _b) (_a) > (_b) ? (_a):(_b)

int maxArea(int* height, int heightSize) {
    
    int left, right, max_area, comp_area;
    
    
    if (!height || heightSize <= 0) {
        
        return 0;
    }
    
    left = max_area = comp_area = 0;
    right = heightSize-1;
    
    
    while (left < right) {
        
        comp_area = (right - left) * (MIN(height[left], height[right]));
        max_area = MAX(max_area, comp_area);
        
        
        if (height[left] > height[right]) {
            
            right--;
        } else {
            left++;
        }
    } // while
    
    return max_area;
    
}
