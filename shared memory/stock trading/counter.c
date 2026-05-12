#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <semaphore.h>

int main() {

    int shmid = shmget(1234, sizeof(int), 0666 | IPC_CREAT);

    int *counter = (int *)shmat(shmid, NULL, 0);
    *counter = 0;

    sem_t sem;
    sem_init(&sem, 1, 1);

    pid_t pid = fork();

    if (pid == 0) {
        // reader
        for (int i=0; i<10; i++) {
            sem_wait(&sem);
            printf("counter = %d\n", *counter);
            sem_post(&sem);
            sleep(1);
        }
    } else {
        // writer
        for (int i=0; i<10; i++) {
            sem_wait(&sem);
            (*counter)++;
            sem_post(&sem);
            sleep(1);
        }

        wait(NULL);

        shmdt(counter);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}