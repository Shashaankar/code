#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>

/** Given an integer x, find square root of it. If x is not a perfect
 * square, then return floor(√x).
 *
 * Examples:
 *
 * Input: x = 4
 * Output: 2
 *
 * Input: x = 11
 * Output: 3
 * */


int _get_squareroot(int x) {

    int mid_square = 0, mid =1;
    int start = 1, end = 1, res = 1;

    if (x == 1 || x== 0) {
        return x; 
    } else if (x < 0) {
        printf("\n Imaginary root, invalid number ");
        return -1;
    }

    start = 1;
    end = x/2;
    mid_square = 1;
    /** square root of x is always less than x/2 for all integer x >= 1 */
    while(start <= end) {

        mid = (start + end)/2;
        mid_square = mid * mid;

        if (mid_square == x) {
            return mid;
        }
        if (mid_square < x) {
            start = mid+1;
            res = mid;
        } else {
            end = mid-1;
        }
    }

    return res;

}

/** Belwo progrm prints square root of integers from 1 - 10 */
void main() {

    int i = 0;

    for (i=0; i < 10000; i++) {

        printf("\nsquare root of %d:=%d", i, _get_squareroot(i));
    }
} 
