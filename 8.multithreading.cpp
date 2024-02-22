#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *myThreadFun(void *vargp) {
    sleep(1);
    printf("Printing GeeksQuiz from Thread\n");
    return NULL;
}

int main() {
    pthread_t thread_id;

    printf("Before Thread\n");

    // Corrected the typo in pthread_create
    if (pthread_create(&thread_id, NULL, myThreadFun, NULL) != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    // Corrected the typo in pthread_join
    if (pthread_join(thread_id, NULL) != 0) {
        perror("pthread_join");
        exit(EXIT_FAILURE);
    }

    printf("After Thread\n");

    return 0;
}