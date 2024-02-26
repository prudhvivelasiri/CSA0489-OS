#include <stdio.h>

#define MEMORY_SIZE 100
#define PROCESS_COUNT 5

// Structure to represent a process
struct Process {
    int id;
    int size;
};

// Function to simulate the first fit memory allocation strategy
void firstFit(struct Process processes[], int memory[]) {
    int i, j;

    for (i = 0; i < PROCESS_COUNT; ++i) {
        for (j = 0; j < MEMORY_SIZE; ++j) {
            if (memory[j] == 0 && j + processes[i].size <= MEMORY_SIZE) {
                // Allocate memory for the process
                for (int k = 0; k < processes[i].size; ++k) {
                    memory[j + k] = processes[i].id;
                }
                printf("Process %d allocated using First Fit starting at position %d\n", processes[i].id, j);
                break;
            }
        }

        if (j == MEMORY_SIZE) {
            printf("Process %d could not be allocated using First Fit\n", processes[i].id);
        }
    }
}

// Function to simulate the best fit memory allocation strategy
void bestFit(struct Process processes[], int memory[]) {
    int i, j;

    for (i = 0; i < PROCESS_COUNT; ++i) {
        int bestFitStart = -1;
        int bestFitSize = MEMORY_SIZE + 1;

        for (j = 0; j < MEMORY_SIZE; ++j) {
            if (memory[j] == 0 && j + processes[i].size <= MEMORY_SIZE) {
                int freeBlockSize = 0;

                // Calculate the size of the free block
                for (int k = j; k < MEMORY_SIZE && memory[k] == 0; ++k) {
                    freeBlockSize++;
                }

                // Check if it's a better fit
                if (freeBlockSize >= processes[i].size && freeBlockSize < bestFitSize) {
                    bestFitStart = j;
                    bestFitSize = freeBlockSize;
                }
            }
        }

        if (bestFitStart != -1) {
            // Allocate memory for the process
            for (int k = 0; k < processes[i].size; ++k) {
                memory[bestFitStart + k] = processes[i].id;
            }
            printf("Process %d allocated using Best Fit starting at position %d\n", processes[i].id, bestFitStart);
        } else {
            printf("Process %d could not be allocated using Best Fit\n", processes[i].id);
        }
    }
}

// Function to simulate the worst fit memory allocation strategy
void worstFit(struct Process processes[], int memory[]) {
    int i, j;

    for (i = 0; i < PROCESS_COUNT; ++i) {
        int worstFitStart = -1;
        int worstFitSize = -1;

        for (j = 0; j < MEMORY_SIZE; ++j) {
            if (memory[j] == 0 && j + processes[i].size <= MEMORY_SIZE) {
                int freeBlockSize = 0;

                // Calculate the size of the free block
                for (int k = j; k < MEMORY_SIZE && memory[k] == 0; ++k) {
                    freeBlockSize++;
                }

                // Check if it's a worse fit
                if (freeBlockSize >= processes[i].size && freeBlockSize > worstFitSize) {
                    worstFitStart = j;
                    worstFitSize = freeBlockSize;
                }
            }
        }

        if (worstFitStart != -1) {
            // Allocate memory for the process
            for (int k = 0; k < processes[i].size; ++k) {
                memory[worstFitStart + k] = processes[i].id;
            }
            printf("Process %d allocated using Worst Fit starting at position %d\n", processes[i].id, worstFitStart);
        } else {
            printf("Process %d could not be allocated using Worst Fit\n", processes[i].id);
        }
    }
}

int main() {
    int memory[MEMORY_SIZE] = {0};  // 0 indicates free memory
    struct Process processes[PROCESS_COUNT] = {{1, 20}, {2, 10}, {3, 30}, {4, 5}, {5, 15}};

    // Simulate First Fit
    printf("First Fit Simulation:\n");
    firstFit(processes, memory);

    // Reset memory
    for (int i = 0; i < MEMORY_SIZE; ++i) {
        memory[i] = 0;
    }

    // Simulate Best Fit
    printf("\nBest Fit Simulation:\n");
    bestFit(processes, memory);

    // Reset memory
    for (int i = 0; i < MEMORY_SIZE; ++i) {
        memory[i] = 0;
    }

    // Simulate Worst Fit
    printf("\nWorst Fit Simulation:\n");
    worstFit(processes, memory);

    return 0;
}
