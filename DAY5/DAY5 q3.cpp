#include <stdio.h>

#define MAX_BLOCKS 100

int main() {
    int indexBlock[MAX_BLOCKS];
    int totalBlocks = 0;

    int choice;

    do {
        // Display menu
        printf("\nFile Allocation Strategy Menu:\n");
        printf("1. Add Block to File\n");
        printf("2. Display Index Block\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add Block to File
                if (totalBlocks < MAX_BLOCKS) {
                    indexBlock[totalBlocks] = totalBlocks + 1;
                    totalBlocks++;
                    printf("Block added to the file.\n");
                } else {
                    printf("File is full. Cannot add more blocks.\n");
                }
                break;

            case 2:
                // Display Index Block
                if (totalBlocks > 0) {
                    printf("\nIndex Block:\n");
                    for (int i = 0; i < totalBlocks; ++i) {
                        printf("Block %d: %d\n", i + 1, indexBlock[i]);
                    }
                } else {
                    printf("No blocks in the file.\n");
                }
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
