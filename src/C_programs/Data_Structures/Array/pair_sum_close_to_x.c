#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>



/** Given a sorted array and a number x, find a pair in array whose sum
 * is closest to x.
 * Examples:
 * Input: arr[] = {10, 22, 28, 29, 30, 40}, x = 54
 * Output: 22 and 30
 *
 * Input: arr[] = {1, 3, 4, 7, 10}, x = 15
 * Output: 4 and 10
 * */

#define DIFF(_a, _b) (((_a) > (_b)) ? (_a -_b):(_b -_a))
//#define DEBUG 


void _print_pair_sum_to_x(int *arr_ptr, int size, int x) {

    int left_index = 0, right_index = 0, sum = -1, diff = -1;
    int l_pair = -1, r_pair = -1;

    if (!arr_ptr || x <=0 || size <=0) {

        printf("\n_sum_to_x: wrong parameters \n");
        exit(-1);
    }

    /** Initialize */
    left_index = l_pair = 0;
    right_index = r_pair = size-1;
    diff = 0;
    sum = arr_ptr[left_index] + arr_ptr[right_index];
    diff = DIFF(sum, x);

#if defined(DEBUG)
    printf("\nINIT: %d, %d", sum, diff);
#endif

    while (left_index < right_index) {

#if defined(DEBUG)
        printf("\nLOOP: val1:=%d val2:=%d, %d, %d", arr_ptr[left_index], arr_ptr[right_index], sum, diff);
#endif
        if (sum < x) {

            if (DIFF(sum, x) < diff) {
                diff = DIFF(sum, x);
                l_pair = left_index;
                r_pair = right_index;
            }
            left_index++;
            sum = arr_ptr[left_index] + arr_ptr[right_index];

        } else {

            if (DIFF(sum, x) < diff) {
                diff = DIFF(sum, x);
                l_pair = left_index;
                r_pair = right_index;
            }
            right_index--;
            sum = arr_ptr[left_index] + arr_ptr[right_index];
        }

    }

    printf("\nPair := %d, %d, difference :=%d\n", arr_ptr[l_pair], arr_ptr[r_pair], diff);


}

void main() {


    int arr[] = {10, 22, 28, 29, 30, 40};
    int x = 38;

    _print_pair_sum_to_x(arr, sizeof(arr)/sizeof(int), x);
} 
