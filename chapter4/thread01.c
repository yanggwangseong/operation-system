#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

void* thread_function(void* arg) {
    printf("Thread is running\n");
    return NULL;
}

int main() {
    pid_t pid;

    pid = fork();
    if (pid < 0) {
        // fork 실패 시 에러 처리
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        // 자식 프로세스
        printf("Child process created\n");
        
        pid_t child_pid = fork();
        if (child_pid < 0) {
            perror("fork failed");
            return 1;
        }

        if (child_pid == 0) {
            // 손자 프로세스
            printf("Grandchild process created\n");
        } else {
            // 자식 프로세스에서 스레드 생성
            pthread_t thread;
            if (pthread_create(&thread, NULL, thread_function, NULL) != 0) {
                perror("pthread_create failed");
                return 1;
            }

            // 스레드 종료 대기
            pthread_join(thread, NULL);
        }
    } else {
        // 부모 프로세스는 자식 프로세스를 기다림
        wait(NULL);
    }

    return 0;
}
