#include <stdio.h>

#define MAX_RECORDS 100

// Structure to represent a file record
struct Record {
    int id;
    char name[50];
    int age;
};

int main() {
    struct Record fileSystem[MAX_RECORDS];
    int totalRecords = 0;

    int choice;

    do {
        // Display menu
        printf("\nFile System Menu:\n");
        printf("1. Add Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Record by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add Record
                if (totalRecords < MAX_RECORDS) {
                    printf("\nEnter record details:\n");
                    printf("ID: ");
                    scanf("%d", &fileSystem[totalRecords].id);
                    printf("Name: ");
                    scanf("%s", fileSystem[totalRecords].name);
                    printf("Age: ");
                    scanf("%d", &fileSystem[totalRecords].age);

                    totalRecords++;
                    printf("Record added successfully!\n");
                } else {
                    printf("File system is full. Cannot add more records.\n");
                }
                break;

            case 2:
                // Display All Records
                if (totalRecords > 0) {
                    printf("\nAll Records:\n");
                    for (int i = 0; i < totalRecords; ++i) {
                        printf("ID: %d, Name: %s, Age: %d\n",
                               fileSystem[i].id, fileSystem[i].name, fileSystem[i].age);
                    }
                } else {
                    printf("No records to display.\n");
                }
                break;

            case 3:
                // Search Record by ID
                if (totalRecords > 0) {
                    int searchID;
                    printf("\nEnter the ID to search: ");
                    scanf("%d", &searchID);

                    int found = 0;
                    for (int i = 0; i < totalRecords; ++i) {
                        if (fileSystem[i].id == searchID) {
                            printf("Record found:\n");
                            printf("ID: %d, Name: %s, Age: %d\n",
                                   fileSystem[i].id, fileSystem[i].name, fileSystem[i].age);
                            found = 1;
                            break;
                        }
                    }

                    if (!found) {
                        printf("Record with ID %d not found.\n", searchID);
                    }
                } else {
                    printf("No records to search.\n");
                }
                break;

            case 4:
                // Exit
                printf("Exiting the file system program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}
