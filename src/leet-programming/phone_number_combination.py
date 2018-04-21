#!/bin/python

class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        digit_map = {'0':" ", '1':"*", '2':"abc", '3':"def", '4':"ghi", '5':"jkl", '6':"mno", '7':"pqrs", '8':"tuv", '9':"wxyz"}
        ret_list = []
        
        if digits == None:
            return None
            
        # Special case for single digit
        if len(digits) == 1:
            str = digit_map[digits]
            for ch in str:
                ret_list.append(ch)
            
            return ret_list
        
        # First form the base list with first two digits    
        if len(digits) >= 2:
            str0 = digit_map[digits[0]]
            str1 = digit_map[digits[1]]
            
            for ch0 in str0:
                for ch1 in str1:
                    app_str = ch0+ch1
                    ret_list.append(app_str)

                        
        if (len(digits) > 2):
            index = 2 # Already processed first two digits
            while (index < len(digits)):
                strn = digit_map[digits[index]]
                #print "string to be looped %s" % (strn)
                
                orig_list = ret_list
                ret_list = []
                for ch in strn:
                    for item in orig_list:
                        app_str = item+ch
                        ret_list.append(app_str)
                
                index += 1
        
        
        #print ret_list
        return ret_list
    
            
            

        
        
