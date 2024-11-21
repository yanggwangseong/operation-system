#include <stdio.h>
#include <unistd.h>

int main(){
    pid_t pid;
    pid = fork();
    printf("Hello, Process!\n");
}

/**
 * 부모 프로세스(P0)이 실행중(Running) 상태에서 fork()를 호출 합니다.
 * 운영체제는 부모 프로세스의 PCB(Process Control Block) 정보를 복사하여 자식 프로세스의 PCB를 만듭니다.
 * 자식 프로세스는 초기에는 New 상태로 생성된다.
 * 자식 프로세스는 fork()이후의 명령어 주소인 PC(프로그램 카운터)를 가지고 있기 떄문에
 * CPU 스케줄링에 따라서 부모 프로세스가 running 되거나 자식 프로세스가 runnung 될때 다음 실행 할 명령어인
 * printf가 실행 되는 것입니다. 그래서 총 2번 실행 됩니다.
 */

/**
 * 
 * 출력 결과
 * Hello, Process!
 * Hello, Process!
 */