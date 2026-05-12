#include <stdio.h>

int main() {

    int n;
    printf("enter no. of requests:" );
    scanf("%d", &n);

    int req[n];
    printf("enter requests: ");
    for (int i=0; i<n; i++) scanf("%d", &req[i]);

    int head;
    printf("enter head: ");
    scanf("%d", &head);

    int total=0;

    printf("Order: %d", head);

    // 1. sort
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (req[i] > req[j]) {
                int temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }

    int idx;

    // 2. find first larger request
    for (int i=0; i<n; i++) {
        if (req[i] > head) {
            idx = i;
            break;
        }
    }

    // 3. move right
    for (int i=idx; i<n; i++) {
        total += abs(head - req[i]);
        head = req[i];
        printf("-> %d", head);
    }

    // 4. reverse
    for (int i=idx-1; i>= 0; i--) {
        total += abs(head - req[i]);
        head = req[i];
        printf("-> %d", head);
    }

    printf("\n");

    printf("total movement = %d\n", total);

    return 0;
}