"""
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
"""
class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        
        i = len(a)-1
        j = len(b)-1
        sum = 0
        carry = 0
        ret_str = []
        
        while i>=0 or j>=0:
            
            sum = 0
            if i>=0 and a[i] == '1':
                sum = sum+1
                
            if j>=0 and b[j] == '1':
                sum = sum+1
                
            
            sum = sum+carry
            
            
            if sum >=2:
                carry = 1
            else:
                carry = 0
                    
            if sum == 3 or sum == 1:
                ret_str.insert(0,'1')
            else:
                ret_str.insert(0,'0')
                    
            
            i = i-1
            j = j-1
            
        if carry == 1:
            ret_str.insert(0,'1')
            
        #print ret_str
        
        return ''.join(ret_str)
