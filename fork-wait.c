#include <stdio.h>
#include <unistd.h>

int main(){

    pid_t pid;

    /* 새 프로세스를 생성한다(fork) */
    pid = fork();

    if( pid < 0 ){ /* 오류가 발생했음 */
        fprintf(stderr, "Fork Failed");
        return 1;
    }else if (pid == 0 ){ /* 자식 프로세스 */
        execlp("/bin/ls", "ls", NULL);
    }else { /* 부모 프로세스 */
        wait(NULL);
        printf("Child Complete");
    }

    return 0;
}