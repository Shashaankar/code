#include<stdio.h>
#include <string.h>
#include <assert.h>

/** 
 * i18n (where 18 stands for the number of letters between the first i
 * and the last n in the word “internationalization,”) Wiki it.
 * Generate all such possible i18n strings for any given string. for eg.
 * "careercup"=&gt;"c7p","ca6p","c6up","car5p","ca5up","care4p","car4up","caree3p","care3up"..till
 * the count is 0 which means its the complete string again.
 */

#define DEBUG 

int _get_last_index(char *str, int j) {
    /** Return last index of char at index 'j' in given string str */

    assert(str);
    int str_len = strlen(str);
    int i=0;
    char ch = str[j];
    int ind = j;
    assert( !(ind < 0 || ind >= str_len));

    /** loop through string from j to strlen to get the final index */
    for (i = j+1; i < str_len; i++) {
        if (str[i] == ch) {
            ind = i;
        }
    }

    /** Either the same index as passed in or updated one with last
     * index */
    return ind;
}


void print_combination(char *str, int i, int ind, int j){
    int p,q;

    printf("str combination:\n");

    for (p=0; p<strlen(str); ) {

        if (p == 0) {

            /** print characters from 0 - index i */
            if (i != 0) {
                
                for (q = 0; q < i; q++) {
                    printf("%c", str[q]);
                }
            }

            /** print characters from i - j */
            if (i != j) {
                for (q = i; q < j; q++) {
                    printf("%c", str[q]);
                }
            }

            printf("%c %d %c", str[j], (ind - j - 1), str[ind]);
            p = ind+1;

        } else {
            printf("%c", str[p]);
            p++;
        }
    }
    printf("\n");
}

int main() {

    int i = 0, j = 0, ind = 0;
    char *str = "careercup";
    int str_len = strlen(str);
    printf("\n%s\n", str);

    for (i = 0; i < str_len; i++) {
        for (j=i; j< str_len; j++) {

            ind = 0;
            ind = _get_last_index(str, j);

#if defined(DEBUG)
            printf("\nind  = %d, j = %d, i = %d\n", ind, j, i);
#endif

            if (j != ind) {
                print_combination(str, i, ind, j);
            } else {
                /** Do not print as we have not found any last index of
                 * a char */
            }
        }
    }
}
