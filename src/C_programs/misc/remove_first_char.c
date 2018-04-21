#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>




void main() {


    char *str = "ABCD";
    char str1[] = {'A', 'B', 'C', 'D'};
    printf("\n%x", str);
    str++;
    printf("\n%x", str);


    printf("\n%s", str);
    printf("\n%s", str+1);




} 
