#include <stdio.h>

int main() {
    int base[3] = {1000,2000,3000};
    int limit[3] = {400,500,300};
    int segment[] = {0,1,2};
    int offset[] = {200,600,150};

    for (int i=0; i<3; i++) {
        printf("segment %d offset %d\n", segment[i], offset[i]);
        if (offset[i] < limit[segment[i]]) {
            int physical = base[segment[i]] + offset[i];
            printf("physical address = %d\n\n", physical);
        } else printf("segmentation fault\n\n");
    }

    return 0;
};
