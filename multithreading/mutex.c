#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

pthread_mutex_t lock;

void *print_headlines(void *arg) {
    char* source = (char *) arg;
    for (int i=1; i<=5; i++) {
        pthread_mutex_lock(&lock);
        printf("%s headline %d\n", source, i);
        usleep(100000);
        pthread_mutex_unlock(&lock);
    }
    pthread_exit(NULL);
}

int main() {

    pthread_mutex_init(&lock, NULL);

    pthread_t t1, t2, t3;
    char s1[] = "BBC";
    char s2[] = "CNN";
    char s3[] = "Reuters";

    pthread_create(&t1, NULL, print_headlines, &s1);
    pthread_create(&t2, NULL, print_headlines, &s2);
    pthread_create(&t3, NULL, print_headlines, &s3);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    return 0;
}