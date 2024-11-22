#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main(){
    int i;

    for(i = 0; i< 4; i++)
        fork();

    printf("Hello, fork()!\n");

    return 0;
}

/**
 * 출력 결과
 * 프로세스 16개 생성
Hello, fork()!
Hello, fork()!
Hello, fork()!
Hello, fork()!                                                                                                                                                               
Hello, fork()!
Hello, fork()!
Hello, fork()!
Hello, fork()!
Hello, fork()!
Hello, fork()!
Hello, fork()!
Hello, fork()!
Hello, fork()!
Hello, fork()!
Hello, fork()!
Hello, fork()!
 */