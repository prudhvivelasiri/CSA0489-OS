#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the shared resource
int shared_variable = 0;

// Define a mutex lock
pthread_mutex_t mutex_lock;

// Function to simulate a critical section
void* critical_section(void* arg) {
    int thread_id = *((int*)arg);

    for (int i = 0; i < 5; i++) {
        // Lock the mutex before accessing the shared resource
        pthread_mutex_lock(&mutex_lock);

        // Access the shared resource
        shared_variable++;
        printf("Thread %d: Shared Variable = %d\n", thread_id, shared_variable);

        // Unlock the mutex after accessing the shared resource
        pthread_mutex_unlock(&mutex_lock);

        // Simulate some non-critical section work
        usleep(rand() % 1000);
    }

    pthread_exit(NULL);
}

int main() {
    // Initialize the mutex lock
    pthread_mutex_init(&mutex_lock, NULL);

    // Create two threads
    pthread_t thread1, thread2;
    int thread_id1 = 1, thread_id2 = 2;

    pthread_create(&thread1, NULL, critical_section, (void*)&thread_id1);
    pthread_create(&thread2, NULL, critical_section, (void*)&thread_id2);

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destroy the mutex lock
    pthread_mutex_destroy(&mutex_lock);

    return 0;
}
