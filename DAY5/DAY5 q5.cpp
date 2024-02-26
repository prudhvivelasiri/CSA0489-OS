#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, initialPosition, totalHeadMovement = 0;

    // Input the number of disk requests
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    // Input the initial position of the disk head
    printf("Enter the initial position of the disk head: ");
    scanf("%d", &initialPosition);

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

    // Simulate FCFS disk scheduling algorithm
    for (int i = 0; i < n; ++i) {
        totalHeadMovement += abs(initialPosition - requests[i]);
        initialPosition = requests[i];
    }

    // Display the total head movement
    printf("\nTotal Head Movement: %d\n", totalHeadMovement);

    // Free allocated memory
    free(requests);

    return 0;
}
