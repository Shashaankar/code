#include<stdio.h>
#include<string.h>

void compare(char *a1, char *a2) {

    char temp1[10];
    char temp2[10];
    int i , index1, index2;
    i = index1 = index2 = 0;

    for(i=0; i < strlen(a1); i++) {
        temp1[index] = a1[i];
        index++;
    }
    for(i=0; i < strlen(a2); i++) {
        temp1[index] = a2[i];
        index++;
    }
    for(i=0; i < strlen(a2); i++) {
        temp2[index] = a2[i];
        index++;
    }
    for(i=0; i < strlen(a1); i++) {
        temp2[index] = a1[i];
        index++;
    }


}

char* largest_number(int *A, int len) {

    sort(A, len);
}
