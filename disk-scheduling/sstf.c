#include <stdio.h>
#include <stdlib.h>

int main () {
    int n;
    printf("enter no. of requests: ");
    scanf("%d", &n);
    int req[n];
    int visited[n];
    for (int i=0; i<n; i++) visited[i]=0;
    printf("enter requests: ");
    for (int i=0; i<n; i++) scanf("%d", &req[i]);
    int head;
    printf("enter head: ");
    scanf("%d", &head);

    int total=0;

    printf("Order: %d", head);

    for (int i=0; i<n; i++) {
        int min = 9999;
        int idx = -1;
        for (int j=0; j<n; j++) {
            if (!visited[j] && abs(head-req[j]) < min) {
                min = abs(head-req[j]);
                idx=j;
            }
        }
        visited[idx] = 1;
        total += abs(head-req[idx]);
        head = req[idx];
        printf("-> %d", head);
    }

    printf("\n");

    printf("total head movement: %d\n", total);

}