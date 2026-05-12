#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t empty, full, mutex;
int item = 0;
int value = 0;

void *producer(void *arg) {
    for (int i=0; i<6; i++) {
        sem_wait(&empty);
        sem_wait(&mutex);

        item++;
        value++;

        printf("produced %d\n", value);

        sem_post(&mutex);
        sem_post(&full);

        sleep(1);
    }
}

void *consumer(void *arg) {
    for (int i=0; i<2; i++) {

        sem_wait(&full);
        sem_wait(&mutex);

        printf("consumed %d\n", value);

        item--;

        sem_post(&mutex);
        sem_post(&empty);

        sleep(1);
    }
}

int main() {
    pthread_t b1, c1, c2, c3;

    sem_init(&empty, 0, 5);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    pthread_create(&b1, NULL, producer, NULL);

    pthread_create(&c1, NULL, consumer, NULL);
    pthread_create(&c2, NULL, consumer, NULL);
    pthread_create(&c3, NULL, consumer, NULL);

    pthread_join(b1, NULL);
    pthread_join(c1, NULL);
    pthread_join(c2, NULL);
    pthread_join(c3, NULL);

    return 0;
}