#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <ctype.h>

int main() {

    int alloc[4][3];
    int max[4][3];
    int avail[3];
    int need[4][3];

    printf("please enter allocation matrix: \n");
    for (int i=0; i<4; i++) {
        for (int j=0; j<3; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("please enter max matrix: \n");
    for (int i=0; i<4; i++) {
        for (int j=0; j<3; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    for (int i=0; i<4; i++) {
        for (int j=0; j<2; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for (int i=0; i<3; i++) scanf("%d", &avail[i]);

    int req[3] = {1, 0, 2};
    // check if req is satisfiable
    int p = 1; 

    for (int j=0; j<3; j++) {
        if (req[j] > need[p][j] || req[j] > avail[j]) {
            printf("request denied");
            return 0;
        }
    }

    // pretend to allocate
    for (int i=0; i<3; i++) {
        avail[i] -= req[i];
        alloc[p][i] += req[i];
        need[p][i] -= req[i];
    }

    int finish[4] = {0};
    int safe[4];
    int k = 0;

    for (int cnt=0; cnt<4; cnt++) {
        for (int i=0; i<4; i++) {
            if (finish[i] == 0 || need[i][0] <= avail[0] || need[i][1] <= avail[1] || need[i][2] <= avail[2]) {
                avail[0] += alloc[i][0];
                avail[1] += alloc[i][1];
                avail[2] += alloc[i][2];
                
                finish[i] = 1;
                safe[k++] = i;
            }
        }
    }

    if(k==4) {
        printf("request accepted!\n");
        printf("safe seqence: ");
        for (int i=0; i<4; i++) printf("P%d ", safe[i]);
    } else printf("request denied");

    return 0;
}