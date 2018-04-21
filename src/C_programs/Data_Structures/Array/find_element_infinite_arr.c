#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>

#include "array.h"


/** Find position of an element in a sorted array of infinite numbers
 * Suppose you have a sorted array of infinite numbers, how would you
 * search an element in the array?
 *
 * Source: Amazon Interview Experience.
 *
 * Since array is sorted, the first thing clicks into mind is binary
 * search, but the problem here is that we don’t know size of array.
 * If the array is infinite, that means we don’t have proper bounds to
 * apply binary search. So in order to find position of key, first we
 * find bounds and then apply binary search algorithm
 * */

#define MUL_FACTOR 2
#define ARRAY_SANITY_CHECK(parr, size) do {\
        if (sanity_check_array((parr), (size)) == -1)\
           exit(-1);\
    }while(0)

int binary_search(int *parr, int low, int high, int key) {

    int mid = 0;
    ARRAY_SANITY_CHECK(parr, high);


    while (low < high) {

        mid = (high+low)/2;

        if (key < parr[mid]) {
            /** Update high and low indexes */
            high = mid;
        } else if (key > parr[mid]) {
            low = mid;
        } else if (key == parr[mid]) {
            return mid;
        }
    }

    return -1;

}

int _get_position(int *parr, int key) {

    int low, high, val;

    /** Here the size of the array is unknown and assumed to be always
     * greater than one element */
    ARRAY_SANITY_CHECK(parr, 1);

    low = 0;
    high = 1;
    val = -1;

    while(low < high) {

        printf("\nlow:=%d, high:=%d", low,high);
        if (key == parr[high]) {
            val = high;
            break;
        } else if (key > parr[high]) {

            /** Update indices */
            low = high;
            high = high*MUL_FACTOR;

        } else {
            /** key in between low and high, do binary search between
             * high and low */
            printf("\n bin search, low:=%d, high:=%d", low, high);
            val = binary_search(parr, low, high, key);
            break;
        }

    }

    return val;
}

void main() {

    int arr[] = {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170};
    int val = 0;

    _print_array(arr, sizeof(arr)/sizeof(arr[0]));

    val = _get_position(arr, 10);

    if (val == -1) {

        printf("\nElement does not exists\n");
        return;
    } else {
        printf("\nElement found at position:=%d\n", val);
    }



} 
