#include<stdio.h>


struct test {
    char c;
    double d;
    char p;
    int x;
    double k;
    int a[0];
};

void main() {
    
          printf("size of sruct %d\n", sizeof(struct test));
}
