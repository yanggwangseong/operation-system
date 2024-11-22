#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main(){
    pid_t pid;
    pid = fork();

    if(pid == 0){
        execlp("/bin/ls", "ls", NULL);
        printf("LINE J\n");
        printf("Oops1");
        printf("Opps2");
        printf("Oops3");
    } else if ( pid > 0){
        wait(NULL);
        printf("Child Complete \n");
    }

    return 0;
}

// ls 리스스트를 보여주는 명령어 인데
// execlp를 사용하게 되면
// 예를들어 부모 프로세스(P0)에서 fork 해서 자식 프로세스 (P1)을 만들었는데
// if(pid == 0)으로 자식 프로세스에서 execlp를 사용하게 되면
// 메모리에 저장되어 있는것들을 전부 execlp로 갈아 끼운다고 이해하면 된다.
// 즉, execlp 뒤의 명령어들은 아무것도 실행되지 않는다.