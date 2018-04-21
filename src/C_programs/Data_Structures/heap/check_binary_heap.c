#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>


/**
 * Given an array, how to check if the given array represents a Binary
 * Max-Heap.
 *
 * Examples:
 *
 * Input:  arr[] = {90, 15, 10, 7, 12, 2} 
 * Output: True
 * The given array represents below tree
 *        90
 *             /    \
 *                15      10
 *                  /  \     /
 *                   7    12  2 
*                   The tree follows max-heap property as every
*                   node is greater than all of its descendants.
*
*                   Input:  arr[] = {9, 15, 10, 7, 12, 11} 
*                   Output: False
*                   The given array represents below tree
 *                          9
 *                               /    \
 *                                  15      10
 *                                    /  \     /
 *                                     7    12  11
*                                     The tree doesn't follows max-heap
*                                     property 9 is 
*                                     smaller than 15 and 10, and 10 is
*                                     smaller than 11
 *                                     */


int arr1[] = {90, 15, 10, 7, 12, 2};
int arr2[] = {9, 15, 10, 7, 12, 11};
void _check_max_heap(int *arr, int size) {

    int i = 0, res = 1;
    /** check for max heap */
    for (i=0; (2*i+1 < size) && (2*i+2 < size); i++) {

        if ((arr[i] < arr[2*i+1]) || (arr[i] < arr[2*i+2])){
            res = 0;
            break;
        }
    }

    if (!res) {
        printf("\n Arr not a binary heap");
    } else {
        printf("\n Arr is a binary heap");
    }

}

void main() {

    _check_max_heap(arr1, sizeof(arr1)/sizeof(arr1[0]));
    _check_max_heap(arr2, sizeof(arr2)/sizeof(arr2[0]));

} 
