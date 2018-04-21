#include <stdio.h>


int reverse(int x) {
    
    int val,res;
    int flag = 0; // set for negative numbers
    int max_int = 1<<31;
    
    //printf("max_int = %d\n", max_int);
    val = res = 0;
    if (x < 0) {
        
        flag = 1;
        val = -x;
    } else {
        val = x;
    }
    
    if (x == 0) {
        return 0;
    }
    
    while(val) {
        
        /* Handle overflow condition */
        if (res != 0 && max_int/res < 10 && max_int/res > -10) {
            return 0;
        }
        
        res = res * 10 + val%10;
        val = val/10;
    }
    
    if(flag) {
        return -res;
    }
    
    return res;
}


int isPalindrome(int x) {
    
    int val,rev_val,flag;
    
    val = rev_val = flag = 0;
    
    if (x == 0) {
        return 1;
    }
    if (x < 0) {
        val = -x;
        flag = 1;
    } else {
        val = x;
    }
    
    
    /* reverse the integer */
    rev_val = reverse(val);
    
    printf("val = %d, rev_val = %d\n", val, rev_val);
    
    while(val && rev_val) {
        
        if (val != rev_val) {
            return 0;
        }
        
        val /= 10;
        rev_val /= 10;
    }
    
    if (val || rev_val) {
        
        return 0;
    }
    
    /* If -ve values are not palindrome */
    if (flag) {
        
        return 0;
    }
 
    return 1;   
}


int
main()
{
    printf("Is palindrome number %d: %d\n", -2147447412, isPalindrome(-2147447412));

    return 0;
}

