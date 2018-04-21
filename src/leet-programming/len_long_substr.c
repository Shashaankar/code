#include<stdio.h>
#include<stdlib.h>

/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

TODO: Failing for very large strings:"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopq
*/


#define BMAP_LEN 256

int
str_map(char ch, int *p_str_bmap, int len)
{
    
    // assert check if ASCII value of ch is greater than len
    int index = (int)ch;
    
    //printf("%d : ch value; val = %d\n", index, p_str_bmap[index]);
    
    if (p_str_bmap[index]) {
        
        //printf("already there\n");
        return 1;
    }
    p_str_bmap[index] = 1;
    //printf("new value\n");
    return 0;
}

void
memzero_str(int *p_str_bmap, int len)
{
    // TODO: Optimize the integer array to actual bitmap
    // Assert check if p_str bmap is NULL
    
    int i = 0;
    for (i=0; i < len; i++) {
        p_str_bmap[i] = 0;
    }
    //memzero(p_str_bmap, sizeof(int) * len);
}

int lengthOfLongestSubstring(char* s) {
    
    if (!s) {
        return 0;
    }
    
    int i,j,len,max_len;
    int *str_bmap = NULL;
    
    i = j = len = max_len = 0;
    
    str_bmap = malloc(sizeof(int) * BMAP_LEN);
    
    memzero_str(str_bmap, BMAP_LEN);
    
    for (j=0; s[j]; j++) {
    
        /* Check for each sequence starting with j */
        i = j;
        memzero_str(str_bmap, BMAP_LEN);
        len = 0;
        
        /* Start of new sequence */
        while (s[i]) {
            
            if (!(str_map(s[i], str_bmap, BMAP_LEN))) {
                
                /* If the char at i doesnot exist in current string bmap */
                len++;
                if (max_len < len) {
                    max_len = len;
                    //printf("max_len set = %d\n", max_len);
                }
                
            } else {
            
                /* Reset values to prepare for next substring */
                memzero_str(str_bmap, BMAP_LEN);
                /* Set current ch */
                len = 1;
                str_map(s[i], str_bmap, BMAP_LEN);
                
            }
            i++;
        }
    } // for loop
    
    // assert check if max_len is less than len
    
    //printf("max_len is %d\n", max_len);
    return max_len;
}#define BMAP_LEN 256

int
str_map(char ch, int *p_str_bmap, int len)
{
    
    // assert check if ASCII value of ch is greater than len
    int index = (int)ch;
    
    //printf("%d : ch value; val = %d\n", index, p_str_bmap[index]);
    
    if (p_str_bmap[index]) {
        
        //printf("already there\n");
        return 1;
    }
    p_str_bmap[index] = 1;
    //printf("new value\n");
    return 0;
}

void
memzero_str(int *p_str_bmap, int len)
{
    // TODO: Optimize the integer array to actual bitmap
    // Assert check if p_str bmap is NULL
    
    int i = 0;
    for (i=0; i < len; i++) {
        p_str_bmap[i] = 0;
    }
    //memzero(p_str_bmap, sizeof(int) * len);
}

int lengthOfLongestSubstring(char* s) {
    
    if (!s) {
        return 0;
    }
    
    int i,j,len,max_len;
    int *str_bmap = NULL;
    
    i = j = len = max_len = 0;
    
    str_bmap = malloc(sizeof(int) * BMAP_LEN);
    
    memzero_str(str_bmap, BMAP_LEN);
    
    for (j=0; s[j]; j++) {
    
        /* Check for each sequence starting with j */
        i = j;
        memzero_str(str_bmap, BMAP_LEN);
        len = 0;
        
        /* Start of new sequence */
        while (s[i]) {
            
            if (!(str_map(s[i], str_bmap, BMAP_LEN))) {
                
                /* If the char at i doesnot exist in current string bmap */
                len++;
                if (max_len < len) {
                    max_len = len;
                    //printf("max_len set = %d\n", max_len);
                }
                
            } else {
            
                /* Reset values to prepare for next substring */
                memzero_str(str_bmap, BMAP_LEN);
                /* Set current ch */
                len = 1;
                str_map(s[i], str_bmap, BMAP_LEN);
                
            }
            i++;
        }
    } // for loop
    
    // assert check if max_len is less than len
    
    //printf("max_len is %d\n", max_len);
    return max_len;
}


int
main() 
{
    printf("main: Len of lonest substring is %d\n", lengthOfLongestSubstring("abcabcbb"));

    return 0;
}





