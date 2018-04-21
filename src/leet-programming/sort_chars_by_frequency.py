#!/bin/python



class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        
        ch_count = dict()
        #print len(s)
        
        for i in range(len(s)):
            
            if ord(s[i]) in ch_count:
                ch_count[ord(s[i])] += 1
            else:
                ch_count[ord(s[i])] = 1
                
                
        # sort it based on counters in decreasing order
        
        #print ch_count
        sorted_ch_count = sorted(ch_count.items(), key=operator.itemgetter(1), reverse=True)
        #print sorted_ch_count
        ret_str = ""
        key_dict = dict()
        for item in sorted_ch_count:
            #print item
            key_dict = item
            freq = key_dict[1]
            ch = key_dict[0]
            #print type(freq)
            #print type(ch)
            while freq:
                #print (str(unichr(ch)))
                ret_str += (str(unichr(ch)))
                freq -= 1
                #print ret_str
            
        print ret_str
        return ret_str
        
