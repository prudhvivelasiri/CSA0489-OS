#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5

int buffer = 0; // Shared resource

sem_t mutex, write_block;
int readers_count = 0;

// Reader thread function
void* reader(void* arg) {
    int reader_id = *((int*)arg);

    // Enter critical section for readers_count
    sem_wait(&mutex);
    readers_count++;
    if (readers_count == 1) {
        sem_wait(&write_block);
    }
    sem_post(&mutex);

    // Reading the shared resource (buffer)
    printf("Reader %d reads: %d\n", reader_id, buffer);

    // Exit critical section for readers_count
    sem_wait(&mutex);
    readers_count--;
    if (readers_count == 0) {
        sem_post(&write_block);
    }
    sem_post(&mutex);

    pthread_exit(NULL);
}

// Writer thread function
void* writer(void* arg) {
    int writer_id = *((int*)arg);

    // Enter critical section for writers
    sem_wait(&write_block);

    // Writing to the shared resource (buffer)
    buffer++;
    printf("Writer %d writes: %d\n", writer_id, buffer);

    // Exit critical section for writers
    sem_post(&write_block);

    pthread_exit(NULL);
}

int main() {
    // Initialize semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&write_block, 0, 1);

    // Create threads
    pthread_t readers[3], writers[2];
    int reader_ids[] = {1, 2, 3};
    int writer_ids[] = {1, 2};

    for (int i = 0; i < 3; i++) {
        pthread_create(&readers[i], NULL, reader, (void*)&reader_ids[i]);
    }

    for (int i = 0; i < 2; i++) {
        pthread_create(&writers[i], NULL, writer, (void*)&writer_ids[i]);
    }

    // Join threads
    for (int i = 0; i < 3; i++) {
        pthread_join(readers[i], NULL);
    }

    for (int i = 0; i < 2; i++) {
        pthread_join(writers[i], NULL);
    }

    // Destroy semaphores
    sem_destroy(&mutex);
    sem_destroy(&write_block);

    return 0;
}
