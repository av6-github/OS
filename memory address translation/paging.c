#include <stdio.h>

int main () {

    int n;
    printf("enter size of page table: ");
    scanf("%d", &n);

    int page_table[n];
    printf("page table entries: ");
    for (int i=0; i<n; i++) scanf("%d", &page_table[i]);

    int va[] = {0x1A3F, 0x2B10};

    int page_size = 4096; // 4KB

    for (int i=0; i<2; i++) {
        int page = va[i]/page_size;
        int offset = va[i]%page_size;
        int frame = page_table[page];

        int physical = frame*page_size+offset;

        printf("virtual address = 0x%X\n", va[i]);
        printf("page = %d offset = %d\n", page, offset);
        printf("physical address = 0x%X\n\n", physical);
    }

    return 0;
}