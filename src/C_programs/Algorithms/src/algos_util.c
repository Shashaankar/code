#include <stdio.h>
#include <stdlib.h>




void _print_list(int **list, int len) {
    int i=0;

    if (!list || !*list) {
        printf("_print_list: List is empty \n");
    }

    for (i=0; i<len; i++) {
        printf("_printlist: %d\n", *(*list + i));
    }
}


/** swap */
void _swap(int *a, int *b) {
    int temp=0;

    temp = *a;
    *a = *b;
    *b = temp;
}


/** @brief: This function takes last element as pivot, places the pivot
 * element at its correct position in sorted array, and places all smaller (smaller
 *    than pivot) to left of pivot and all greater elements to right of pivot */

unsigned int  _partition(int **list, int l, int h) {

    int p = *list[h];  // pivot element
    int i,j=0;
    i = l-1;

    for (j=l; j <= h-1; j++) {

        if (*list[j] < p) {
            i++;
            _swap(list[i], list[j]);
        }

    }

    _swap(list[i+1], list[h]);
    return (i+1);

}


_quick_sort(int **list, int l, int h) {
    
    if (!list || !*list) {
        printf("_quick_sort: List is empty \n");
        return;
    }


    if (l < h) {
        int p = _partition(list, l, h);

        _quick_sort(list, l, p-1);
        _quick_sort(list, p+1, h);
    }
}
