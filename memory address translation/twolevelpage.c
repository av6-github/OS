#include <stdio.h>

int main() {
    unsigned int va = 0x00403004;

    // extract fields
    int l1 = (va >> 22) & 0x3FF; 
    int l2 = (va >> 12) & 0x3FF;
    int offset = va & 0x3FF;

    // given values
    int l2_base = 5000;
    int frame = 7;
    int physical = frame * 4096 + offset;


    printf("virtual address = 0x%X\n", va);
    printf("L1 index = %d\n", l1);
    printf("L2 index = %d\n", l2);
    printf("offset = %d\n", offset);

    printf("L1[%d] -> L2 table base = %d\n", l1, l2_base);
    printf("L2[%d] -> frame = %d\n", l2, frame);
    printf("physical address = %d\n", physical);

    return 0;
}