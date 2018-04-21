#include <stdio.h>
#define DEBUG 0

/**
 *
 * @Desc: Given a sorted array with consequitive elements, find the
 * element which is missing from thelist.
 *
 * NOTE: 
 * Assumtionis there will be ONLY ONE number missing from the
 * given list.
 *
 * @Time complexity: O(logn)
 *
 * @Space complexity: O(1) or constant
 */

int find(int *arr, int size) {

    int left,right,mid;
    int exp_value;

    if (!arr || size <= 0) {
        return 0;
    }

    left = 0;
    right = size-1;
    while (left < right) {
    
        mid         = (left+right)/2;
        exp_value   = arr[left] + (mid - left);
#if DEBUG
        printf("DEBUG: left = %d, right = %d, arr[mid]=%d, exp_val=%d\n", 
                                            left, right, arr[mid], exp_value);
#endif

        if (arr[mid] != exp_value) {

            right = mid;

        } else {
            left = mid;

            /* Condition where there are only two elements in the array */
            if ((right - left == 1) && (arr[left]+1 != arr[right])) {
                return arr[left]+1;
            } else if (right - left == 1) {
                /* This condition catches cases where no number is
                 * missing from the given list */
                break;
            }
        }
    } // while


    /* If no number is missing from the list */
    return 0;
}
int main() {

    int loop;
    int a[][5] = {   {4,6,7,8,9},
                    {4,5,7,8,9},
                    {4,5,6,8,9},
                    {4,5,6,7,8} };

    int b[][6] = {
                    {10,12,13,14,15,16},
                    {10,11,13,14,15,16},
                    {10,11,12,14,15,16},
                    {10,11,12,13,15,16},
                    {10,11,12,13,14,16}
                    };

    for (loop=0; loop<4; loop++) {

        printf("Test case%d numbers..\n", loop);
        for (int i = 0; i<5; i++) {
            printf("\t %d", a[loop][i]);
        }
        printf("\n");

        printf("missing number = %d\n", find(&a[loop], 5));
    }

    printf("\n\n");
    for (loop=0; loop<5; loop++) {

        printf("\nTest case%d numbers..\n", loop);
        for (int i = 0; i<6; i++) {
            printf("\t %d", b[loop][i]);
        }
        printf("\n");

        printf("missing number = %d\n", find(&b[loop], 6));
    }

    return 0;

}
