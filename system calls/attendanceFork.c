#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main() {

    pid_t pid;
    pid = fork();

    if (pid < 0) printf("fork failed\n");
    else if (pid == 0) {
        // child
        printf("child process\n");
        printf("child pid = %d\n", getpid());
        printf("parent pid = %d\n", getppid());

        int fd;

        fd = open("attendance.txt", O_WRONLY | O_CREAT | O_TRUNC);
        write(fd, "Child attended\n", strlen("Child attended\n"));
        close(fd);
    }  else {
        // parenmt

        wait(NULL);

        printf("parent process\n");
        printf("pid = %d\n", getpid());

        int fd;

        fd = open("attendance.txt", O_WRONLY|O_CREAT|O_APPEND, 0644);
        write(fd, "Parent attended\n", strlen("Parent attended\n"));
        close(fd);
    }

    return 0;
}