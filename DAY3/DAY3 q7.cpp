#include <stdio.h>

#define MAX_BLOCKS 50
#define MAX_PROCESS 50

int memory[MAX_BLOCKS];
int process[MAX_PROCESS];
int block_count, process_count;

// Function to allocate memory using First Fit algorithm
void firstFit() {
    int i, j;
    for (i = 0; i < process_count; i++) {
        int allocated = 0;

        for (j = 0; j < block_count; j++) {
            if (memory[j] >= process[i]) {
                memory[j] -= process[i];
                printf("Allocated Process %d to Block %d\n", i + 1, j + 1);
                allocated = 1;
                break;
            }
        }

        // If no suitable block is found
        if (!allocated) {
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

    // Perform First Fit allocation
    firstFit();

    return 0;
}
