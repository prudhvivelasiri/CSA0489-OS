#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    char filename[] = "example.txt";
    mode_t permissions = S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IXGRP | S_IROTH | S_IWOTH | S_IXOTH;

    if (chmod(filename, permissions) == 0) {
        printf("File permissions set successfully.\n");
    } else {
        perror("Error setting file permissions");
        exit(EXIT_FAILURE);
    }

    return 0;
}
