/*
Write a program that opens a file (with the open () system call) and then calls 
fork() to create a new process. Can both the child and parent access the file
descriptor returned by open ()? What happens when they are writing to the file
concurrently, i.e., at the same time?
*/

#include <iostream>
#include <fcntl.h>
#include <unistd.h> 

int main() {
    int fd = open("output.txt", O_CREAT | O_WRONLY | O_TRUNC);
    if (fd < 0) {
        perror("open");
        return 1;
    }
    
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) { // Child process
        std::cout << "Child process writing to file...\n";
        write(fd, "Child writing\n", 14);
    } else { // Parent process
        std::cout << "Parent process writing to file...\n";
        write(fd, "Parent writing\n", 15);
    }

    close(fd);

    return 0;
}