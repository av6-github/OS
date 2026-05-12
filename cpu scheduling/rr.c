#include <stdio.h>

int main() {

    int bt[4] = {10, 4, 6, 3};
    int rem[4];

    int tq = 3;

    int completion[4];

    int time = 0;

    for (int i=0; i<4; i++) {
        rem[i] = bt[i];
    }

    int done;

    while (1) {
        done = 1;
        for(int i=0; i<4; i++) {
            if (rem[i] > 0) {
                done = 0;
                if (rem[i] > tq) {
                    time += tq;
                    rem[i] -= tq;
                } else {
                    time += rem[i];
                    completion[i] = time;
                    rem[i] = 0;
                }
            }
        }

        if (done == 1) break;
    }

    printf("completion time: \n");
    for (int i=0; i<4; i++) {
        printf("J%d\t%d\n", i+1, completion[i]);
    }

    float avg = 0;

    for(int i = 0; i < 4; i++) {
        avg += completion[i];
    }

    avg /= 4;

    printf("\nAverage Turnaround Time = %.2f\n",
           avg);


    return 0;
}