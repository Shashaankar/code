
/*
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, and 
there exists one unique longest palindromic substring.

*/


int getExpandedMatchingLen(char *s, int left, int right)
{
    int L,R,i;
    L = left;
    R= right;
    i = 0;
    
    while (L >=0 && R < strlen(s) && s[L] == s[R]) {
        L--;
        R++;
    }

    return (R - L - 1);
}

char* subString(char *s, int start, int end) {
    
    char *ret = NULL;
    int len,i;
    
    len = end - start +2;
    if (len <= 0) {
        return NULL;
    }
    
    ret = malloc(sizeof(char)*len);
    printf("len = %d\n", len);
    
    for (i=0;i<len-1;i++) {
        ret[i]=s[start];
        start++;
    }
    
    ret[len-1] = '\0';
    printf("ret = %s\n", ret);
    return ret;
}

char* longestPalindrome(char* s) {
    
    int i,len1,len2,len,start,end,actual_len;
    
    if (!s) {
        return NULL;
    }
    actual_len = strlen(s);
    i = len1 = len2 = len = end = start = 0;
    for (i=0; i < strlen(s); i++) {
        
        len1 = getExpandedMatchingLen(s, i, i);
        len2 = getExpandedMatchingLen(s, i, i+1);
        
        len = len1>len2?len1:len2;
        
        if (len > end-start+1) {
            
            start = i - (len-1)/2;
            end = i + len/2;
        }
        
    }
    
    printf("start = %d, end = %d\n", start, end);
    // return substring
    
    
#if 0    
    // Point S to the start indexed char
    i = 0;
    while(i < start) {
        s++;
        i++;
    }
    
    if (end+1 < actual_len) {
        printf("assigning end+1 to null\n");
        printf("s= %s\n",s);
        s[end+1] = NULL;
        printf("s= %s\n",s);
    }
#endif
    
    return subString(s, start, end);
    
}
