#include <stdio.h>

int main() {
    int bt[5] = {6, 4, 2, 3, 1};
    int pr[5] = {2, 1, 3, 1, 4};
    int p[5] = {1, 2, 3, 4, 5};

    int tat[5], wt[5];

    for (int i=0; i<5; i++) {
        for (int j=i+1; j<5; j++) {
            if (pr[i] > pr[j]) {
                int temp;

                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;

            }
        }
    }

    wt[0] = 0;

    for (int i=1; i<5; i++) {
        wt[i] = wt[i-1] + bt[i-1]; 
    }

    for (int i=1; i<5; i++) {
        tat[i] = wt[i] + bt[i]; // TAT = WT + BT
    }

    printf("Process\tBT\tWT\tTAT\n");
    for (int i=0; i<5; i++) {
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    float avgWaitTime = 0;
    float avgTurnaroundTime = 0;
    for (int i=0; i<5; i++) {
        avgWaitTime += wt[i];
        avgTurnaroundTime += tat[i];
    }

    avgWaitTime = avgWaitTime/5;
    avgTurnaroundTime = avgTurnaroundTime/5;


    // gantt chart

    printf("Gantt Chart: \n");

    printf("0");
    int time = 0;

    for (int i=0; i<5; i++) {
        printf(" ---P%d--- ", p[i]);
        time += bt[i];
        printf("%d", time);
    }

    printf("\n");
    printf("\nAverage Waiting Time = %.2f\n", avgWaitTime);
    printf("\nAverage Turnaround Time = %.2f\n", avgTurnaroundTime);

}