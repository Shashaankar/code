"""
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
"""
class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        
        if len(digits) == 0:
            return [1]
        
        carry = 0
        i = len(digits)-1
        
        
        while i>=0 :
            n = digits[i]
            
            if i == len(digits)-1:
                n = n+1
            
            n = n + carry
            
            if n<10:
                digits[i] = n
                carry = 0
            else:
                digits[i] = n%10
                carry = n/10
            
            if carry == 0:
                break
        
            i = i-1
        
        if carry != 0:
            digits.insert(0,carry)
            
        return digits
