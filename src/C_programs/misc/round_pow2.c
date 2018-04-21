#include <stdio.h>

#define ROUND_UP_PWR2(x, align)    (((int) (x) + ((align)-1)) & ~((align)-1))
int main() {

    int x = 40;
    printf("\n%d", ROUND_UP_PWR2(x, 4));
}
