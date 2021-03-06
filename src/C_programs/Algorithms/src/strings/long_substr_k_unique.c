#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>


/** Find the longest substring with k unique characters in a given
 * string
 * Given a string you need to print longest possible substring that has
 * exactly M unique characters. If there are more than one substring of
 * longest possible length, then print any one of them.
 *
 * "aabbcc", k = 1
 * Max substring can be any one from {"aa" , "bb" , "cc"}.
 *
 * "aabbcc", k = 2
 * Max substring can be any one from {"aabb" , "bbcc"}.
 *
 * "aabbcc", k = 3
 * There are substrings with exactly 3 unique characters
 * {"aabbcc" , "abbcc" , "aabbc" , "abbc" }
 * Max is "aabbcc" with length 6.
 *
 * "aaabbb", k = 3
 * There are only two unique characters, thus show error message. 
 */

#define MAX_CHARS 26
/** Assuming the input string contains only alphabets and no special
 * chars */

char *str = "aabacbebebe";

int is_valid(int *count, int k) {

    int val = 0, i = 0;
    for (i=0; i < MAX_CHARS; i++) {
        if (count[i] > 0)
            val++;
    }

    return (k > val);
}


void _get_long_sub_str(char *str, int k) {

    int curr_start = 0,curr_end = 0, max_wind_start = 0, max_wind_size = 0;
    int count[MAX_CHARS] = {};
    int len = strlen(str);
    int i = 0, unique = 0;

    for (i=0; i < len; i++) {

        if (count[str[i]-'a'] == 0) {
            unique++;
        }
    }

    if (unique < k) {
        printf("\n Error there are not enough unique characters in the string ");
        exit(-1);
    }

    max_wind_start = 0;
    max_wind_size = 1;
    curr_start = 0;
    curr_end = 0;
    /** Increment first index counter */
    count[str[0]-'a']++;

    for (i=1; i<len; i++) {

        count[str[i]-'a']++;
        curr_end++;

        /** Check if more than k unique chars in current window then
         * move from left i.e. curr start */
        while (!is_valid(count, k)) {
            /** Move window from left */
            count[str[i]-'a']--;
            curr_start++;
        }

        /** Check if max window size is needed */
        if ((curr_end - curr_start + 1) > max_wind_size) {
            max_wind_size = curr_end - curr_start + 1;
            max_wind_start = curr_start;
        }

    }

    /** Now print the result in max variables */
    printf("\nMax length sub str of %s starts from %d to %d", str, max_wind_start, max_wind_size+max_wind_start);
}

void main() {

    _get_long_sub_str(str, 2);


} 
