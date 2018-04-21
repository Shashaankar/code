#include <stdio.h>
#include <stdlib.h>


int main() {

    int *list = malloc(4*sizeof(int));

    list[0] = 0;
    list[1] = 8;
    list[2] = 5;
    list[3] = 3;

    printf("list size: %d\n", 4);

    _print_list(&list, 4);

    free(list);
}
