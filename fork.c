#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    // fork a child process

    pid = fork(); // fork system call
    if(pid < 0){
        fprintf(stderr, "Fork Failed");
        return 1;
    }else if ( pid == 0){ // child process
        execlp("/bin/ls", "ls", NULL);
    }else { // parent process
        wait(NULL);
        printf("Child complete");
    }
    return 0;
}

/**
 * 실제 실행 결과는
 * `execlp("/bin/ls", "ls", NULL);` 
 * 여기가 먼저 실행되고
 * wait가 실행되고
 * `printf("Child complete")` 여기가 실행된다.
 */

// Process Termination
// exit() -> system call