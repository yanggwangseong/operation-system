#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main(){
    int i;
    pid_t pid;

    for(i = 0; i< 4; i++){
        pid = fork();
        printf("Hello, fork %d\n", pid);
    }

    return 0;
}

/**
 * 출력 결과
 * printf에 pid만 추가 했을 뿐인데 16개보다 훨씬 많이 나온다 뭐지 ???
 Hello, fork 30873
Hello, fork 30874
Hello, fork 0
Hello, fork 30875
Hello, fork 0
Hello, fork 30877
Hello, fork 30876
Hello, fork 0
Hello, fork 0
Hello, fork 30878
Hello, fork 30880
Hello, fork 0
Hello, fork 30879
Hello, fork 0
Hello, fork 0
Hello, fork 30883
Hello, fork 0
Hello, fork 30885
Hello, fork 30881
Hello, fork 0
Hello, fork 0
Hello, fork 0                                                                                                                                                                
Hello, fork 30882
Hello, fork 30884
Hello, fork 0
Hello, fork 30886
Hello, fork 0
Hello, fork 0
Hello, fork 30887
Hello, fork 0
 */
