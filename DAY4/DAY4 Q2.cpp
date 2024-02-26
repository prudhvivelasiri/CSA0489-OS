#include <stdio.h>
#include <stdlib.h>

// Function to create and write to a file
void createAndWriteToFile() {
    FILE *file = fopen("example.txt", "w");

    if (file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "Hello, this is a sample text.\n");
    fprintf(file, "File management operations in C.\n");

    fclose(file);
}

// Function to read from a file
void readFromFile() {
    FILE *file = fopen("example.txt", "r");

    if (file == NULL) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    printf("Contents of the file:\n");

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);
}

// Function to append to a file
void appendToFile() {
    FILE *file = fopen("example.txt", "a");

    if (file == NULL) {
        perror("Error opening file for appending");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "Appending more text to the file.\n");

    fclose(file);
}

int main() {
    // Create and write to a file
    createAndWriteToFile();

    // Read from the file
    readFromFile();

    // Append to the file
    appendToFile();

    // Read again after appending
    printf("\nAfter appending:\n");
    readFromFile();

    return 0;
}
