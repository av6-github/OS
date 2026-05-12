#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <ctype.h>

int main() {

    int alloc[3][2];
    int req[3][2];
    int avail[2] = {0, 0};

    int finish[3] = {0};
    for (int cnt=0; cnt<3; cnt++) {

        for (int i=0; i<3; i++) {

            if (!finish[i] &&
                req[i][0] <= avail[0] &&
                req[i][1] <= avail[1]) {

                avail[0] += alloc[i][0];
                avail[1] += alloc[i][1];

                finish[i] = 1;
            }
        }
    }

    int deadlock=0;

    for (int i=0; i<3; i++) {
        if (!finish[i]) {
            deadlock=1;
            printf("P%d in deadlock\n", i);
        }
    }

    if (!deadlock) printf("no deadlock detected");

    return 0;
}