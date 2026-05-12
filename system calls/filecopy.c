#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    int source, dest;
    int buffer[100];
    int bytesRead;

    struct stat s1, s2;

    // open source file
    source = open("source.txt", O_RDONLY);
    if (source < 0) {
        printf("error opening source file\n");
        return 1;
    }

    //open destination file
    dest = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest < 0) {
        printf("error creating destination file\n");
        return 1;
    }

    // read and write loop
    while ((bytesRead = read(source, buffer, sizeof(buffer))) > 0) {
        if (write(dest, buffer, bytesRead) != bytesRead) {
            printf("error writing file\n");
            return 1;
        }
    }

    if (bytesRead < 0) {
        printf("error reading file\n");
        return 1;
    }

    close(source);
    close(dest);

    stat("source.txt", &s1);
    stat("destination.txt", &s2);

    if (s1.st_size == s2.st_size) {
        printf("copy successful\n");
    } else printf("copy failed\n");
    
    return 0;
}