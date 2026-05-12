#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {

    int shmid;
    shmid = shmget(1234, 5*sizeof(int), 0666);

    int *temp;
    temp = (int *)shmat(shmid, NULL, 0);

    for (int i=0; i<5; i++) {
        printf("read %d\n", temp[i]);
    }

    shmdt(temp);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;

}