/*
Write a program that creates a child process, and then in the child closes
standard output (STDOUT FILENO). What happens if the child calls printf() to
print some output after closing the descriptor?
*/
#include <iostream>
#include <unistd.h> 

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed.");
        return 1;
    }

    if (pid == 0) { 
        close(STDOUT_FILENO);
        printf("I will not print!\n");
    } 
    else { 
        sleep(1);
        printf("I will print!\n");
    }

    return 0;
}
/*
When a child process closes the standard output (STDOUT_FILENO), any attempt to print
using printf() will fail because the output stream is closed.
*/