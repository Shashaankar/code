"""
Implement int sqrt(int x).

Compute and return the square root of x.
"""
class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        
        if (x == 0 or x == 1):
            return x
            
        prod = 1
        start = 1
        end = x
        result = 0
        
        while start <= end:
            mid = (start+end)/2
            prod = mid*mid
            
            if prod == x:
                return mid
                
            if prod > x:
                end = mid-1
                
            if prod < x:
                start = mid+1
                result = mid
                
                
        return result
