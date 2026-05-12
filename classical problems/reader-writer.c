#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex, write_lock;
int reader_count=0;

void *reader(void *arg) {
    for (int i=0; i<3; i++) {
        sem_wait(&mutex);
        reader_count++;
        if (reader_count==1) sem_wait(&write_lock);
        sem_post(&mutex);
        
        printf("reader is reading...\n");
        
        sleep(1);

        sem_wait(&mutex);
        reader_count--;
        if (reader_count == 0) sem_post(&write_lock);
        sem_post(&mutex);
    }
}

void *writer(void *arg) {
    for (int i=0; i<3; i++) {
        sem_wait(&write_lock);
        printf("writer is writing...\n");

        sleep(1);

        sem_post(&write_lock);
    }
}

int main() {

    pthread_t r1, r2, w1;

    sem_init(&mutex, 0, 1);
    sem_init(&write_lock, 0, 1);

    pthread_create(&r1, NULL, reader, NULL);
    pthread_create(&r2, NULL, reader, NULL);
    pthread_create(&w1, NULL, writer, NULL);

    pthread_join(r1, NULL);
    pthread_join(r2, NULL);
    pthread_join(w1, NULL);

    return 0;
}