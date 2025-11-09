#include <Windows.h>
#include <stdio.h>
#include <processthreadsapi.h>
#include <synchapi.h>
#include <handleapi.h>

int main() {

    // Define the structs that hold startup information and process information.
    STARTUPINFOW startupInfo = { 0 };
    PROCESS_INFORMATION processInfo = { 0 };

    // Create process
    if (!CreateProcessW(
        L"C:\\Windows\\system32\\notepad.exe", //lpApplicationName
        NULL, //lpCommandLine
        NULL, //lpProcessAttributes
        NULL, //lpThreadAttributes
        FALSE, //bInheritHandles
        NORMAL_PRIORITY_CLASS, //dwCreationFlags
        NULL, //lpEnvironment
        NULL, //lpCurrentDirectory
        &startupInfo, // lpStartupInfo
        &processInfo // lpProcessInformation
    )) {
        // Catch errors and print a message to the terminal.
        printf("Failed to create process, error: %ld", GetLastError());
        return EXIT_FAILURE;
    }

    // If process started successfully, print information about the process.
    printf("\nProcess started successfully.");
    printf("\nProcess ID (PID):\t %ld", processInfo.dwProcessId);
    printf("\nProcess handle:\t\t %ld", processInfo.hProcess);
    printf("\nThread ID (TID):\t %ld", processInfo.dwThreadId);
    printf("\nThread handle:\t\t %ld", processInfo.hThread);
    
    // Open the process that was created.
    if (!OpenProcess(
        PROCESS_ALL_ACCESS, // dwDesiredAccess,
        FALSE, // bInheritHandle,
        processInfo.dwProcessId // dwProcessId
    )) {
        // Catch errors and print a message to the terminal.
        printf("Failed to open process, error: %ld", GetLastError());
        return EXIT_FAILURE;
    };

    // Wait for the process.
    printf("\nEntering wait state...");
    WaitForSingleObject(
        processInfo.hProcess, // hHandle,
        INFINITE //dwMilliseconds
    );

    // Close handle and process.
    printf("\nProgram done! Closing...");
    CloseHandle(
        processInfo.hThread// hObject
    );
    CloseHandle(
        processInfo.hProcess// hObject
    );

    return EXIT_SUCCESS;
}
