#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>

#include "array.h"


/** Given an unsorted array that may contain duplicates. Also given a
 * number k which is smaller than size of array. Write a function that
 * returns true if array contains duplicates within k distance.
 *
 * Examples:
 *
 * Input: k = 3, arr[] = {1, 2, 3, 4, 1, 2, 3, 4}
 * Output: false
 * All duplicates are more than k distance away.
 *
 * Input: k = 3, arr[] = {1, 2, 3, 1, 4, 5}
 * Output: true
 * 1 is repeated at distance 3.*/

/** Solution: 
 *
 * 1. Double for loop to search and time complexity is O(n*k) 
 * 2. Hashing to find out occurence of more than one entry with window
 * size k
 * 3. TODO XOR ? */


int _check_duplicate(int *parr, int i, int k, int prev_sum) {

    while (k) {

        if (parr[i] ^ prev_sum == prev_sum) {

            printf("\nContains duplicate\n");
            return 0;
        }

        prev_sum = prev_sum ^ parr[i];
        k--;
        i++;
    }

    return prev_sum;

}


void main() {

    int arr[] = {1, 2, 3, 4, 1, 2, 3, 4};
    int i = 0, prev_sum = 0, k = 3, ret = 0;

    for (i = 0; (i + k)  < sizeof(arr)/sizeof(arr[0]); i++) {

        ret = _check_duplicate(arr, i, k, prev_sum);

        if (ret == 0) {
            break;
        }
        prev_sum =ret;

    }



} 
