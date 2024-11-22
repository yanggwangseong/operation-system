#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t pid;
    pid = fork();
    if (pid > 0)
        sleep(3);       
        wait(NULL);
        
    printf("Hello, Process! %d\n", pid);
}
