#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>


/** Given a string, that contains special character together with
 * alphabets (‘a’ to ‘z’ and ‘A’ to ‘Z’), reverse the string in a way
 * that special characters are not affected.
 *
 * Examples:
 *
 * Input:   str = "a,b$c"
 * Output:  str = "c,b$a"
 * Note that $ and , are not moved anywhere.  
 * Only subsequence "abc" is reversed
 *
 * Input:   str = "Ab,c,de!$"
 * Output:  str = "ed,c,bA!$"
 * */


#define IS_ALPHA(_chr)  ((((int)(_chr) >= (int)'a' && (int)(_chr) <= (int)'z') || ((int)(_chr) >= (int)'A' && (int)(_chr) <= (int)'Z')) ? 1:0)
char str[] = "Ab,c,de!$";


void _reverse_str(char *str) {


    int start = 0, end = 0;
    
    end = strlen(str)-1;

    while (start!=end) {

        if (IS_ALPHA(str[start])) {

            if (IS_ALPHA(str[end])) {

                /** swap characters */
                char temp;
                temp = str[start];
                str[start] = str[end];
                str[end] = temp;

                start++;
                end--;
                continue;
            } else {
                /** Move end index only */
                end--;
                continue;
            }
        } else {

            /** Dont swap Move start index*/
            start++;
        }
    }

}

void main() {

    printf("\nBefore: %s", str);
    printf("%d", IS_ALPHA(str[0]));
    str[0] = str[6];
    //_reverse_str(str);
    printf("\nAfter: %s", str);
} 
