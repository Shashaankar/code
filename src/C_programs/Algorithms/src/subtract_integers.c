#include<stdio.h>
#include <string.h>

#define SRK_MIN(_a, _b) ((_a) < (_b) ? (_a): (_b))
/**
You are given two streams 's_a' and 's_b' of digits. 
Each stream represents an integer 'a' and 'b' from its less significant 
digit to the most significant digit. For example, integer 2048 is 
represented in the stream as 8, 4, 0, 2.
Write a function that subtract two integers 'a - b' and returns the result as a string. 
You are not allowed to buffer entire 'a' or 'b' into a single string, 
i.e. you may access only a single digit per stream at time 
(imagine that 'a' and 'b' are stored in huge files). You may assume that 'a>=b'.
**/

int main() {

    char *str1 = "5402";
    char *str2 = "4201";

    int i=0, val=0;
    int min_len = 0;
    min_len = SRK_MIN(strlen(str1), strlen(str2));
    printf("\nmin_len = %d\n", min_len);

    printf("Value:\n");
    for (i=0; i<min_len; i++) {
        val = (int)(str1[i] - str2[i]);
        printf("%d", val);
    }

}
