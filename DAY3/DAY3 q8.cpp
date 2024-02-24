#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Create a file
    int file_descriptor = open("example_file.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (file_descriptor == -1) {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }

    // Write data to the file
    const char* data_to_write = "Hello, this is a demonstration of UNIX system calls for file management!";
    ssize_t bytes_written = write(file_descriptor, data_to_write, strlen(data_to_write));

    if (bytes_written == -1) {
        perror("Error writing to file");
        close(file_descriptor);
        exit(EXIT_FAILURE);
    }

    printf("Data written to file: %s\n", data_to_write);

    // Close the file
    close(file_descriptor);

    // Open the file for reading
    file_descriptor = open("example_file.txt", O_RDONLY);

    if (file_descriptor == -1) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    // Read data from the file
    char buffer[100];
    ssize_t bytes_read = read(file_descriptor, buffer, sizeof(buffer) - 1);

    if (bytes_read == -1) {
        perror("Error reading from file");
        close(file_descriptor);
        exit(EXIT_FAILURE);
    }

    buffer[bytes_read] = '\0';  // Null-terminate the string

    printf("Data read from file: %s\n", buffer);

    // Close the file
    close(file_descriptor);

    return 0;
}
