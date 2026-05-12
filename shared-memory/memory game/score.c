#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>

int main() {

    int fd = shm_open("/score", O_CREAT|O_RDWR, 0666);
    ftruncate(fd, sizeof(int));

    int *score = mmap(0, sizeof(int), PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);

    pid_t pid = fork();

    if (pid == 0) {
        // reader
        for (int i=0; i<3; i++) {
            sleep(1);
            printf("Score = %d\n", *score);
        }
    } else {
        // writer
        *score = 100;
        sleep(1);
        *score=200;
        sleep(1);
        *score=300;

        wait(NULL);
        munmap(score, sizeof(score));
        shm_unlink("/score");
    }

    return 0;
}