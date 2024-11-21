#include <stdio.h>
#include <unistd.h>

int main(){
    pid_t pid;
    
    pid = fork();
    printf("Hello, Process! %d\n", pid);
}

/**
 * 
 * 출력 결과
 * Hello, Process! 2648
 * Hello, Process! 0
 */