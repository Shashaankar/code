#include<stdio.h>

#define A_ROUND_UP_PWR2(x, align)    (((int) (x) + ((align)-1)) & ~((align)-1))

void main() {

    int x = 76;
    printf("align for %d is %d\n", x, A_ROUND_UP_PWR2(x, 4));
}
