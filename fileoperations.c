#include <stdio.h> // Header file for standard input & output

// Main function
int main() {
		
    // Set file pointer
    FILE* fptr;
    // Set message variable
    char message[124] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";


    // (1) Create file
    fptr = fopen("test.txt", "w");
    // Check if file was created
    if (fptr == NULL) {
        perror("\nError opening file");
        return 1;
    }
    else printf("\nFile opened successfully to start write operation");


    // (2) Write to file
    fputs(message, fptr);
    printf("\nFile written successfully");
    // Close file
    fclose(fptr);
    printf("\nFile closed successfully to end write operation");


    // (3) Read from file
    fptr = fopen("test.txt", "r");
    printf("\nFile opened successfully to start read operation");
    // create a string big enough to hold the file contents
    char fileContent[124];
    // get file contents
    fgets(fileContent, 124, fptr);
    printf("\nFile contents: %s", fileContent);
    // Close file
    fclose(fptr);
    printf("\nFile closed successfully to end read operation");

	// Return code: program executed successfully and terminated without any errors
	return 0;
}
