#include <stdio.h> // Header file for standard input & output
#include <time.h> // Header file for time functionality

// Main function
int main() {
	
	// Point to struct for storing time information
	struct tm* ptr;
	
	// Create variable to store time information
	time_t currentTime;

	// Get current time since linux epoch, store it in variable
	currentTime = time(NULL);
	
	// Convert current time since linux epoch to local time, store it in struct
	ptr = localtime(&currentTime);

	// Print current time to terminal
	printf("The current date and time: %s \n", asctime(ptr));
		
	// Return code: program executed successfully and terminated without any errors
	return 0;
}
