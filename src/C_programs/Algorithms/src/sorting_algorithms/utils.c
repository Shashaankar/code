#include<stdio.h>
#include "utils.h"

void print_array(int *a, int n)
{
        int i=0;
        if (!a || n < 0) {
                printf("\nWARNING: NULL array given");
                return;
        }

        printf("\n Array contents are ...");
        for(i=0; i<n; i++) {
                printf("\n%d", a[i]);
        }
}

