#include <stdio.h>
#include <stdlib.h>

// Enumeration for head movement direction
enum Direction {
    LEFT = -1,
    RIGHT = 1
};

int main() {
    int n, initialPosition, totalHeadMovement = 0;
    enum Direction direction;

    // Input the number of disk requests
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    // Input the initial position of the disk head
    printf("Enter the initial position of the disk head: ");
    scanf("%d", &initialPosition);

    // Input the direction of head movement
    printf("Enter the direction of head movement (1 for right, -1 for left): ");
    scanf("%d", (int *)&direction);

    // Input the disk requests
    int *requests = (int *)malloc(n * sizeof(int));
    if (requests == NULL) {
        printf("Memory allocation error.\n");
        return 1;  // Exit with an error code
    }

    printf("Enter the disk requests:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &requests[i]);
    }

    // Sort the disk requests in ascending order
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (requests[j] > requests[j + 1]) {
                // Swap
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }

    // Simulate SCAN disk scheduling algorithm
    int headIndex = 0;
    while (headIndex < n && requests[headIndex] <= initialPosition) {
        headIndex++;
    }

    // Move the head to the beginning of the requests in the specified direction
    totalHeadMovement += abs(initialPosition - requests[headIndex - 1]);
    initialPosition = requests[headIndex - 1];

    // Traverse the disk requests in the specified direction
    for (int i = headIndex - 1; i >= 0; i--) {
        totalHeadMovement += abs(initialPosition - requests[i]);
        initialPosition = requests[i];
    }

    for (int i = headIndex; i < n; ++i) {
        totalHeadMovement += abs(initialPosition - requests[i]);
        initialPosition = requests[i];
    }

    // Display the total head movement
    printf("\nTotal Head Movement: %d\n", totalHeadMovement);

    // Free allocated memory
    free(requests);

    return 0;
}
