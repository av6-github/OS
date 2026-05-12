#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t fork[3];

void *philosopher(void *arg) {
    int i = *(int *)arg;

    int left = i;
    int right = (i+1) % 3;

    printf("philosopher %d thinking....", i);

    if (i == 2) {
        pthread_mutex_lock(&fork[right]);
        pthread_mutex_lock(&fork[left]);
    } else {
        pthread_mutex_lock(&fork[left]);
        pthread_mutex_lock(&fork[right]);
    }

    printf("philosopher %d eating....", i);
    sleep(1);

    pthread_mutex_unlock(&fork[left]);
    pthread_mutex_unlock(&fork[right]);
}

int main() {
    pthread_t p[3];

    int id[3] = {0,1,2};

    for (int i=0; i<3; i++) {
        pthread_mutex_init(&fork[i], NULL);
    }

    for(int i=0; i<3; i++) {
        pthread_create(&p[i], NULL, philosopher, &id[i]);
    }

    for(int i=0; i<3; i++) {
        pthread_join(p[i], NULL);
    }

    return 0;
}