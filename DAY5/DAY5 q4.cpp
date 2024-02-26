#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 100

// Function to simulate linked allocation
int allocateBlock(int file[], int block) {
    int i;

    // Find an empty block in the file
    for (i = 0; i < MAX_BLOCKS; ++i) {
        if (file[i] == -1) {
            file[i] = block;
            return i;
        }
    }

    return -1; // No empty block found
}

// Function to display the contents of the file
void displayFile(int file[]) {
    printf("\nFile Contents:\n");

    int i = 0;
    while (file[i] != -1) {
        printf("Block %d -> ", file[i]);
        i = file[i];
    }

    printf("NULL\n");
}

int main() {
    int file[MAX_BLOCKS];
    int directory[2] = {-1, -1}; // directory[0] = first block, directory[1] = last block

    int choice, block;
    int blockIndex;

    // Initialize file array
    for (int i = 0; i < MAX_BLOCKS; ++i) {
        file[i] = -1;
    }

    do {
        // Display menu
        printf("\nFile Allocation Strategy Menu:\n");
        printf("1. Allocate Block to File\n");
        printf("2. Display File Contents\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Allocate Block to File
                printf("Enter the block to allocate: ");
                scanf("%d", &block);

                blockIndex = allocateBlock(file, block);

                if (blockIndex != -1) {
                    printf("Block %d allocated to the file at index %d\n", block, blockIndex);

                    if (directory[0] == -1) {
                        // If the file is empty, set the first block in the directory
                        directory[0] = blockIndex;
                    } else {
                        // Update the next pointer of the last block to point to the newly allocated block
                        file[directory[1]] = blockIndex;
                    }

                    // Update the last block in the directory
                    directory[1] = blockIndex;
                } else {
                    printf("File is full. Cannot allocate more blocks.\n");
                }
                break;

            case 2:
                // Display File Contents
                displayFile(file);
                break;

            case 3:
                // Exit
                printf("Exiting the file allocation program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 3);

    return 0;
}
