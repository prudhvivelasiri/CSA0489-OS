#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    // Open a file for reading
    int fd1 = open("input.txt", O_RDONLY);
    if (fd1 == -1) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    // Open a file for writing
    int fd2 = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd2 == -1) {
        perror("Error opening file for writing");
        close(fd1);
        exit(EXIT_FAILURE);
    }

    // Read from the first file and write to the second file
    char buffer[1024];
    ssize_t bytesRead;
    while ((bytesRead = read(fd1, buffer, sizeof(buffer))) > 0) {
        if (write(fd2, buffer, bytesRead) != bytesRead) {
            perror("Error writing to file");
            close(fd1);
            close(fd2);
            exit(EXIT_FAILURE);
        }
    }

    // Seek to a specific position in the second file
    if (lseek(fd2, 10, SEEK_SET) == -1) {
        perror("Error seeking in file");
        close(fd1);
        close(fd2);
        exit(EXIT_FAILURE);
    }

    // Display the contents of the second file after seeking
    char readBuffer[100];
    lseek(fd2, 0, SEEK_SET);  // Move the file cursor back to the beginning
    ssize_t bytesReadAfterSeek = read(fd2, readBuffer, sizeof(readBuffer));
    if (bytesReadAfterSeek > 0) {
        readBuffer[bytesReadAfterSeek] = '\0';
        printf("Contents after seeking:\n%s\n", readBuffer);
    } else {
        perror("Error reading file after seeking");
    }

    // Close the files
    close(fd1);
    close(fd2);

    // Stat example - get information about a file
    struct stat fileStat;
    if (stat("output.txt", &fileStat) == 0) {
        printf("\nFile Information:\n");
        printf("Size: %ld bytes\n", fileStat.st_size);
        printf("Permissions: %o\n", fileStat.st_mode & 0777);
    } else {
        perror("Error getting file information");
    }

    // Open a directory and list its contents
    DIR *dir = opendir(".");
    if (dir != NULL) {
        printf("\nDirectory Listing:\n");
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL) {
            printf("%s\n", entry->d_name);
        }
        closedir(dir);
    } else {
        perror("Error opening directory");
    }

    return 0;
}
