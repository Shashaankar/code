#include<stdio.h>
#include<assert.h>

/** Sort an almost sorted array where only two elements are swapped
 * Given an almost sorted array where only two elements are swapped, how
 * to sort the array efficiently?
 *
 * Example
 *
 * Input:  arr[] = {10, 20, 60, 40, 50, 30}  
 * 30 and 60 are swapped
Output: arr[] = {10, 20, 30, 40, 50, 60}

Input:  arr[] = {10, 20, 40, 30, 50, 60}  
// 30 and 40 are swapped
// Output: arr[] = {10, 20, 30, 40, 50, 60}
//
// Input:   arr[] = {1, 5, 3}
// // 3 and 5 are swapped
// Output:  arr[] = {1, 3, 5}
// Expected time complexity is O(n) and only one swap operation to fix
// the array.
*/

int arr[] = {1, 5, 3};

void print_list(int *arr, int len) {
    int i=0;

    printf("\n Array list is as follows: \n");
    for (i=0; i < len; i++) {
        printf("\t %d", arr[i]);
    }
    printf("\n");
}


void swap(int *arr, int i, int j) {

    int temp = 0;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


void main() {

    int i,len,swap1, swap2;
    i = len = 0;
    swap1 = swap2 = -1;
    len =  sizeof(arr)/sizeof(int);

    printf("\n len = %d", len);

    for (i=0; i < len -1; i++) {

        if (arr[i] > arr[i+1]) {
            if (swap1 == -1) {
                swap1 = i;
                printf("\n swap1 = %d", swap1);
            } else if (swap2 == -1) {
                swap2 = i+1;
                printf("\n swap2 = %d", swap2);
            } else {
                /** */
                printf("\n should not happen as the list must have only one swapped out location ");
            }

        } else {
            /** Nothing to do as the list is in ncreasing order */
        }
    }

    /** After loop is terminated */
    if (swap1 == -1) {
        printf("\nList is already sorted ");
        return;
    }
    if (swap2 == -1) {
        /** should swap adjacent locations */
        swap(arr, swap1, swap1+1);
        print_list(arr, len);
        return;
    }          

    swap(arr, swap1, swap2);
    print_list(arr, len);
    return;

}
