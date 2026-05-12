#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {

    int shmid;
    shmid = shmget(1234, 5*sizeof(int), 0666 | IPC_CREAT);

    int *temp;
    temp = (int *)shmat(shmid, NULL, 0);

    for (int i=0; i<5; i++) {
        temp[i] = 20+i;
        printf("produced %d\n", temp[i]);
    }

    shmdt(temp);
    return 0;

}