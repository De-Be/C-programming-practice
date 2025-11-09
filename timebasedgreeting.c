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

	// Store hour count from struct in variable
	int hour = ptr->tm_hour;

	// Print appropriate greeting based on hour variable count
	if (hour < 12) {
		printf("Good morning! It is currently %s", asctime(ptr)); // If hour variable count is lower than 12, it is morning
	}
	else if (hour > 18) { // 
		printf("Good evening! It is currently %s", asctime(ptr)); // If hour variable count is higher than 18, it is evening
	}
	else {
		printf("Good afternoon! It is currently %s", asctime(ptr)); // If hour variable count is neither lower than 12 nor higher than 18, it must be afternoon
	}
		
	// Return code: program executed successfully and terminated without any errors
	return 0;
}
