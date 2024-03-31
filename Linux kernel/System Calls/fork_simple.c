#include <sys/types.h>
#include <unistd.h>
#include <iostream>

int main() {
    pid_t pid = fork();
    
    if (pid == -1) {
        // Error occurred
        std::cerr << "Error in fork()" << std::endl;
        return 1;
    } else if (pid == 0) {
        // Child process
        std::cout << "Child process: PID = " << getpid() << std::endl;
    } else {
        // Parent process
        std::cout << "Parent process: PID = " << getpid() << ", Child PID = " << pid << std::endl;
    }
    
    // Both parent and child will continue execution from here
    return 0;
}
