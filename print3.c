#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;
    pid = fork();

    if (pid > 0) {
        // 부모 프로세스: fork()의 반환값은 자식의 PID
        printf("Parent process: fork returned pid = %d, my pid = %d\n", pid, getpid());
    } else if (pid == 0) {
        // 자식 프로세스: fork()의 반환값은 0
        printf("Child process: fork returned pid = %d, my pid = %d\n", pid, getpid());
    } else {
        // fork 실패
        perror("fork failed");
    }

    return 0;
}