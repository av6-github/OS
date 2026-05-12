#include <stdio.h>

int main() {

    int total[2] = {3, 4};

    int alloc[4][2];
    int max[4][2];
    int need[4][2];
    int avail[2];

    printf("please enter allocation matrix: \n");
    for (int i=0; i<4; i++) {
        for (int j=0; j<2; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("please enter max matrix: \n");
    for (int i=0; i<4; i++) {
        for (int j=0; j<2; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // calculating available resources per resource type
    avail[0] = total[0];
    avail[1] = total[1];

    // avail = total - alloc;
    for (int i=0; i<4; i++) {
        avail[0] -= alloc[i][0];
        avail[1] -= alloc[i][1];
    }

    // calculating need = max - allocation
    for (int i=0; i<4; i++) {
        for (int j=0; j<2; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int finish[4] = {0};
    int safe[4];
    int k=0;

    for (int cnt=0; cnt<4; cnt++) {
        for (int i=0; i<4; i++) {
            if (finish[i] == 0 && need[i][0] <= avail[0] && need[i][1] <= avail[1]) {
                avail[0] += alloc[i][0];
                avail[1] += alloc[i][1];

                finish[i] = 1;
                safe[k++] = i;

            }
        }
    }

    if (k == 4) {
        printf("safe sequence: ");
        for (int i=0; i<4; i++) {
            printf("P%d ", safe[i]);
        }
    } else printf("system is in deadlock");

    return 0;
}