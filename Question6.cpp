#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstring>

void execute_program(const char* program, char* const args[]) {
    if (execvp(program, args) == -1) {
        perror("Error executing program");
        exit(1);
    }
}

int main() {
    std::string program_name;
    int num_processes;
    char execution_mode;

    std::cout << "closh> ";
    std::getline(std::cin, program_name);

    std::cout << "count> ";
    std::cin >> num_processes;
    std::cin.ignore();
    std::cout << "[p]arallel or [s]equential> ";
    std::cin >> execution_mode;
    std::cin.ignore(); 

    char* const args[] = {const_cast<char*>(program_name.c_str()), nullptr};

    for (int i = 0; i < num_processes; ++i) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        } else if (pid == 0) {
            execute_program(program_name.c_str(), args);
        } else {
            if (execution_mode == 's') {
                waitpid(pid, nullptr, 0);
            }
        }
    }

    if (execution_mode == 'p') {
        for (int i = 0; i < num_processes; ++i) {
            wait(NULL);
        }
    }

    std::cout << "closh> ";
    return 0;
}