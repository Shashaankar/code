#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>


/*** 
 * Two strings str1 and str2 are called isomorphic if there is a one to
 * one mapping possible for every character of str1 to every character
 * of str2. And all occurrences of every character in ‘str1′ map to same
 * character in ‘str2′.
 *
 * Input:  str1 = "aab", str2 = "xxy"
 * Output: True
 * 'a' is mapped to 'x' and 'b' is mapped to 'y'.
 *
 * Input:  str1 = "aab", str2 = "xyz"
 * Output: False
 * One occurrence of 'a' in str1 has 'x' in str2 and 
 * other occurrence of 'a' has 'y'.
 */


char map_table[256][2];

int lookup_insert(char c1, char c2) {

        /** c1 & c2 are already visited */
    if (map_table[(int)c1][0] == c1 && map_table[(int)c2][0] == c2) {

        /** Check for one to one mapping */
        if (map_table[(int)c1][1] == c2 && map_table[(int)c2][1] == c1) {
            printf("\nboth are equal c1=%c, c2=%c", c1, c2);
            return 0;
        } else {
            printf("\nnot equal c1=%c, c2=%c", c1, c2);
            return -1;
        }
    } else if ((map_table[(int)c1][0] != c1 && map_table[(int)c2][0] != c2)) {

        /** Store and create a one to one mapping */
        /** Store mape c1 - > c2 */
        map_table[(int)c1][0] = c1;
        map_table[(int)c1][1] = c2;
        /** Store map c2 -> c1 */
        map_table[(int)c2][0] = c2;
        map_table[(int)c2][1] = c1;
        printf("\nstore in table, c1=%c, c2=%c", c1, c2);
        return 0;
    } else {
        /** many to one or one to many mapping */
        printf("\n many to or one to many mapping");
        return -1;
    }

}

void main() {

    char *str1 = "acb";
    char *str2 = "xxz";

    int str_len1 = 0, i = 0, str_len2=0, res = 0;

    str_len1 = strlen(str1);
    str_len2 = strlen(str2);

    if (str_len1 != str_len2) {
        printf("\n strings are not equal hence can not comapre for isomorphic");
        exit(-1);
    }

    for (i=0; i < str_len1; i++) {

        if (lookup_insert(str1[i], str2[i]) == -1) {
            printf("\nstring1 %c is not equivalen to string2 %c ", str1[i], str2[i]);
            res = -1;
            break;
        }
    }

    if (!res)
        printf("\n Strings %s and %s are isomorphich", str1, str2);

} 
