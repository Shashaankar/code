#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>

/** Local header files */
#include "array.h"


/** Given an unsorted of distinct integers, find the largest pair sum in
 * it. For example, the largest pair sum in {12, 34, 10, 6, 40} is 74
 *
 * */

#define MIN(_a, _b) ((_a > _b) ? _b:_a)
#define MAX(_a, _b) ((_a > _b) ? _a:_b)

int _get_largest_pair_sum(int *arr_ptr, int size) {

    if (!arr_ptr) {
        perror("NULL array pointer");
    }

    
    if (size == 1) {

        printf("\n _pair_sum: Need atleast 2 values in list for the sum ");
        exit(-1);

    }
    int l1,l2, i;

    /** Initialize it to first value */
    l1 = l2 = arr_ptr[0];

    for (i=1; i< size; i++) {

        /** Store the largest of the list */
        if (l1 < arr_ptr[i]) {
            /** Current value of l1 will be second large */
            l2 = l1;
            /** Overwrite l1 which contains largest value in the list */
            l1 = arr_ptr[i];
        }

        /** Store the second largest in l2 */
        l2 = MIN(l2, arr_ptr[i]);
    }

    return l1+l2;

}

void main() {

    int arr[] = {12, 34, 10, 6, 40};

    int x = 0;

    x = _get_largest_pair_sum(arr, sizeof(arr)/sizeof(int));

    printf("\n largest pair sum := %d\n", x);






} 
