/*
3) Write anotoher program using a fork (). The child process should print “hello”; 
the parent process should print “goodbye”. You should try to ensure that the child
process always prints first; can you do this without calling wait() in the parent?
*/
#include <iostream>
#include <unistd.h>

int main() {

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        std::cout << "hello\n";
    } 
    else {
        sleep(1);
        std::cout << "goodbye\n";
    }

    return 0;
}
/*
The child process prints "hello" first because the parent process sleeps for a second.
The parent process prints "goodbye" after the sleep, ensuring the order is maintained 
without needing to call wait().
*/