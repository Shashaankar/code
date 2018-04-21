#include "array.h"


void _print_array(int *parr, int size) {

    int i = 0;

    if (!parr || size == 0) {
        printf("\n_print_array: Error");
        exit(-1);
    }

    printf("\n_print_array: Array elements list");
    for (i = 0; i < size; i++) {

        printf("\n%d", parr[i]);
    }
    printf("\n_print_array: list end");
}


int sanity_check_array(int *parr, int size) {

    if (!parr || size <= 0) {

        printf("\n Array sanity check failed");
        /** Failure */
        return -1;
    }

    /** Success */
    return 0;
}
