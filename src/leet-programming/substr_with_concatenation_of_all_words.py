
# TODO: Optimize for lower time complexity

class Solution(object):


    def checkWords(slef, s, index, words):
        
        j = 0
        word_len = len(words[0])
        i = index
        result = dict()
        found = 0
        
        for word in words:
            for j in range(word_len):
                
                if word[j] != s[i+j]:
                    break
                
                if j == word_len-1:
                    found=1
                    result['found'] = '0'
                    result['word']= word
                    break
                
        
        if found != 1:
            result['found'] = '-1'
        
            
        return result
        
                
                
    
    def checkWordsSubstr(self, s, index, words):

        word_len = len(words[0])
        j = 0
        count = 0
        i = index
        cmp_words = words[:]

        print "compare start index = ", (index)

        while count < len(words):
            result = Solution.checkWords(self, s, i, cmp_words)
            # one match found
            if result['found'] == '0':
                count += 1
                i += word_len
                cmp_words.remove(result['word'])
                print "remove word = %s updated words = %s" % (result['word'], cmp_words)
            else:
                break
                    
        print "word count found = ", (count)
        
        if count == len(words):
            return index
        else:
            return -1
            
            
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        start_ch = []
        ret_list = []
        i = 0

        if len(words) == 0 or len(s) == 0:
            return ret_list
            
        words_len = len(words[0]) * len(words)
        print "words_len = ", (words_len)
        
        if words_len > len(s):
            return ret_list
        
        # start_ch has starting char of all given words
        for word in words:
            start_ch.append(word[0])

        while i < len(s):

            # Need not check for any further
            if i+words_len-1 >= len(s):
                return ret_list

            if s[i] in start_ch:
                ret = Solution.checkWordsSubstr(self, s, i, words)
                
                if ret>=0:
                    print "words substr index found at = ", (ret)
                    ret_list.append(ret)
                    #i += len(words[0])
                    #print "updated i = ", (i)
                    #print words
                
            i += 1
            print "updated i = ", (i)
            print words
            
                


        return ret_list


