#include <stdio.h>

#define MAX_FRAMES 3
#define MAX_PAGES 10

int main() {
    int frames[MAX_FRAMES];
    int pages[MAX_PAGES];
    int pageFaults = 0;
    int n, i, j;

    // Input the number of pages
    printf("Enter the number of pages: ");
    scanf("%d", &n);

    // Input the page reference sequence
    printf("Enter the page reference sequence:\n");
    for (i = 0; i < n; ++i) {
        scanf("%d", &pages[i]);
    }

    // Initialize frames to -1 (indicating an empty frame)
    for (i = 0; i < MAX_FRAMES; ++i) {
        frames[i] = -1;
    }

    // Simulate optimal paging algorithm
    for (i = 0; i < n; ++i) {
        int page = pages[i];
        int pageFound = 0;

        // Check if page is already in a frame
        for (j = 0; j < MAX_FRAMES; ++j) {
            if (frames[j] == page) {
                pageFound = 1;
                break;
            }
        }

        // If page is not in any frame, find the optimal page to replace
        if (!pageFound) {
            int farthestIndex = -1;
            int farthestDistance = -1;

            for (j = 0; j < MAX_FRAMES; ++j) {
                int k;
                int distance = 0;

                for (k = i + 1; k < n; ++k) {
                    if (frames[j] == pages[k]) {
                        break;
                    }
                    distance++;
                }

                if (distance > farthestDistance) {
                    farthestDistance = distance;
                    farthestIndex = j;
                }
            }

            // Replace the farthest page with the current page
            frames[farthestIndex] = page;
            pageFaults++;
        }

        // Display the current state of frames
        printf("Frames: ");
        for (j = 0; j < MAX_FRAMES; ++j) {
            if (frames[j] == -1) {
                printf("- ");
            } else {
                printf("%d ", frames[j]);
            }
        }
        printf("\n");
    }

    // Display the total number of page faults
    printf("\nTotal Page Faults: %d\n", pageFaults);

    return 0;
}
