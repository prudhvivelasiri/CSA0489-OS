#include <stdio.h>

#define MAX_BLOCKS 50
#define MAX_PROCESS 50

int memory[MAX_BLOCKS];
int process[MAX_PROCESS];
int block_count, process_count;

// Function to allocate memory using Worst Fit algorithm
void worstFit() {
    int i, j;
    for (i = 0; i < process_count; i++) {
        int worst_fit_index = -1;
        int worst_fit_size = -1;

        for (j = 0; j < block_count; j++) {
            if (memory[j] >= process[i]) {
                if (worst_fit_index == -1 || memory[j] > memory[worst_fit_index]) {
                    worst_fit_index = j;
                    worst_fit_size = memory[j];
                }
            }
        }

        // If a block is found
        if (worst_fit_index != -1) {
            memory[worst_fit_index] -= process[i];
            printf("Allocated Process %d to Block %d\n", i + 1, worst_fit_index + 1);
        } else {
            printf("Cannot allocate Process %d\n", i + 1);
        }
    }
}

int main() {
    // Input memory blocks
    printf("Enter the number of memory blocks: ");
    scanf("%d", &block_count);

    printf("Enter the size of each memory block:\n");
    for (int i = 0; i < block_count; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &memory[i]);
    }

    // Input processes
    printf("Enter the number of processes: ");
    scanf("%d", &process_count);

    printf("Enter the size of each process:\n");
    for (int i = 0; i < process_count; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &process[i]);
    }

    // Perform Worst Fit allocation
    worstFit();

    return 0;
}
