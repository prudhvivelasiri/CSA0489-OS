#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* threadFunction(void* arg) {
    printf("Inside the new thread\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    int ret;

    // Create a new thread
    ret = pthread_create(&thread, NULL, threadFunction, NULL);

    if (ret != 0) {
        fprintf(stderr, "Error creating thread: %d\n", ret);
        exit(EXIT_FAILURE);
    }

    printf("Inside the main thread\n");

    // Join the thread
    ret = pthread_join(thread, NULL);

    if (ret != 0) {
        fprintf(stderr, "Error joining thread: %d\n", ret);
        exit(EXIT_FAILURE);
    }

    // Demonstrate pthread_equal
    pthread_t mainThread = pthread_self();
    if (pthread_equal(mainThread, thread)) {
        printf("The main thread and the created thread are equal.\n");
    } else {
        printf("The main thread and the created thread are not equal.\n");
    }

    return 0;
}
