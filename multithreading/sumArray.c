#include <stdio.h>
#include <pthread.h>

int arr[100];
int sums[4];

void *calc_sum(void *arg) {
    int thread_no = *(int *) arg;

    int start = thread_no * 25;
    int end = start + 25;

    int sum = 0;

    for (int i=start; i<end; i++) {
        sum += arr[i];
    }

    sums[thread_no] = sum;
    pthread_exit(NULL);

}

int main() {

    for (int i=0; i<100; i++) arr[i] = i+1;

    pthread_t t[4];

    for (int i=0; i<4; i++) {
        pthread_create(&t[i], NULL, calc_sum, &i);
    }

    for (int i=0; i<4; i++) {
        pthread_join(t[i], NULL);
    }

    int total = 0;
    for (int i=0; i<4; i++) {
        total += sums[i];
    }

    printf("Total Sum = %d\n", total);

    return 0;
}