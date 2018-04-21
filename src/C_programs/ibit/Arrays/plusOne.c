#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer array. You need to malloc memory for result array, and fill result's length in length_of_array
 */

int* plusOne(int* A, int n1, int *length_of_array);
void main() {

    int a[] = {1,2,3};

    int *A, len, i;

    A = NULL;
    len = 0;

    A = plusOne(&a[0], 3, &len);
    assert(A);

    for (i=0; i <len; i++) {
        printf("\n %d", A[i]);
    }


}
 
int* plusOne(int* A, int n1, int *length_of_array) {
	// SAMPLE CODE
        /*
         * *length_of_array = n1 + 1; // length of result array
         * int *result = (int *) malloc(*length_of_array * sizeof(int));
         * // DO STUFF HERE. NOTE : length_of_array can be n1 OR n1 + 1. 
         * return result;
         */
         
         int *result = NULL;
         int len, i, j, carry, count_zero;
         len = i = carry = 0;
         
         if (n1 <= 0 || A == NULL) {
             return NULL;
             
         }
         
         // Count number of zeros at the start of array, if any
         count_zero = -1;
         for (i=0; i <n1; i++) {
             
             if(A[i] == 0) {
                 count_zero++;
             } else {
                break;
             }
         }
         
         i = n1-1; // Increment from the end
         while((i >= 0) && (i != count_zero)) {
             
             carry = 0;
             
             if (A[i] < 9) {
                 A[i] += 1;
                 break;
             }
             
             A[i] = 0;
             i--;
             carry = 1;
             
         }
         
         if (count_zero == -1) {
            len = n1;
         } else if(count_zero == (n1-1)) {
           
            len = 1;
              
         } else {
            len = (n1 - count_zero) - 1;    
         }
         
         if (carry) {
             len += 1;
         }
         
         result = malloc(sizeof(int)*len);
         *length_of_array = len;
         //printf("final length= %d\n", len);
         if (carry) {
             
            result[0] = 1;
            j = 1;
         } else {
             
             j = 0;
         }
         
         //Copy other elements
         //printf("result:\n");
         if (count_zero == (n1-1)) {
             result[0] = 1;
             //printf("%d", result[0]);
         }
         for (i=count_zero+1; i<n1; i++) {
             
             result[j] = A[i];
             //printf("\n %d", result[j]);
             j++;
         }
         
         
         
         return result;
         
}

