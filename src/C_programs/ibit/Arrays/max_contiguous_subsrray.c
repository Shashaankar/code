#include <stdio.h>


#define MAX(a, b) ((a) > (b))?(a):(b)

int max_sum_subarray(const int *A, int n);

void main() {

    int arr[]  = {-2,1,-3,4,-1,2,1,-5,4}, i;

    for (i=0; i<sizeof(arr)/sizeof(arr[0]); i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    printf("max contigous sub array = %d\n", max_sum_subarray(arr, sizeof(arr)/sizeof(arr[0])));
}


int max_sum_subarray(const int *A, int n)
{
    int max1,max2,i;

    max1 = A[0];
    max2 = A[0];

    for (i=1; i < n; i++) {

        max2 = MAX(max2 + A[i], A[i]);
        max1 = MAX(max2, max1);

        printf("DEBUG: max1=%d, max2=%d\n", max1, max2);
    }

    return max1;
}
