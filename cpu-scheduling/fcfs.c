#include <stdio.h>

int main() {
    int at[5] = {0, 1, 2, 3, 4};
    int bt[5] = {6, 4, 2, 3, 1};

    int tat[5], wt[5];

    wt[0] = 0; // since fcfs

    for (int i=1; i<5; i++) {
        wt[i] = wt[i-1] + bt[i-1]; 
    }

    for (int i=1; i<5; i++) {
        tat[i] = wt[i] + bt[i]; // TAT = WT + BT
    }

    printf("Process\tAT\tBT\tWT\tTAT\n");
    for (int i=0; i<5; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], wt[i], tat[i]);
    }

    float avgWaitTime = 0;
    for (int i=0; i<5; i++) {
        avgWaitTime += wt[i];
    }

    avgWaitTime = avgWaitTime/5;

    // gantt chart

    printf("Gantt Chart: \n");
    printf("0");
    int time = 0;

    for (int i=0; i<5; i++) {
        printf(" ---P%d--- ", i+1);
        time += bt[i];
        printf("%d", time);
    }

    printf("\n");
    printf("\nAverage Waiting Time = %.2f\n", avgWaitTime);

}