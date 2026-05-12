#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

int main() {

    int fd[2];
    pid_t pid;

    char message[] = "Hello from parent";
    char buffer[100];

    // create pipe
    pipe(fd);

    pid = fork();

    if (pid == 0) {
        // child 
        close(fd[1]); // close write end
        read(fd[0], buffer, sizeof(buffer));

        for (int i=0; buffer[i] != '\0'; i++) {
            buffer[i] = toupper(buffer[i]);
        }

        printf("%s\n", buffer);

        close(fd[0]);
    } else {
        //parent
        close(fd[0]); // close read end
        write(fd[1], message, strlen(message)+1);
        close(fd[1]);
    }

    return 0;
}