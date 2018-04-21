#include <stdio.h>

int main() {

    unsigned int seq_num=0;
    seq_num = 0x87654321;

    printf("\n%x", seq_num);


    seq_num = ((seq_num & 0xF) << 28) | (((seq_num & 0xF0) >> 4) << 24) | (((seq_num & 0xF00) >> 8) << 20) |
                        (((seq_num & 0xF000) >> 12) << 16) | (((seq_num & 0xF0000) >> 16) << 12) |
                        (((seq_num & 0xF00000) >> 20) << 8) | (((seq_num & 0xF000000) >> 24 ) << 4) |
                        ((seq_num & 0xF0000000) >> 28);


    printf("\n%x", seq_num);

    return 0;
}
