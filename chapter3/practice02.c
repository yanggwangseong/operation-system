#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main(){
    /* fork a child process */
    fork();
    
    // 부모(P0)
    // 자식(P1)

    /**
     * P0 -> P1
     */

    /* fork another child process */
    fork();
    // 부모(P0)
    // 자식(P1)
    
    // 새로 생김
    // 자식(P2)
    // 자식(P3)

    /**
     * P0 -> P1
     * P0 -> P2
     * P1 -> P3
     */

    /* and fork another */
    fork();
    // 부모(P0)
    // 자식(P1)
    // 자식(P2)
    // 자식(P3)

    // 새로 생김
    // 자식(P4)
    // 자식(P5)
    // 자식(P6)
    // 자식(P7)

    /**
     * P0 -> P1
     * P0 -> P2
     * P0 -> P4
     * P1 -> P3
     * P1 -> P5
     * P2 -> P6
     * P3 -> P7
     */

    printf("Hello, fork()!\n");
    return 0;
}

/**
 * 출력 결과
Hello, fork()!
Hello, fork()!
Hello, fork()!
Hello, fork()!
Hello, fork()!
Hello, fork()!
Hello, fork()!
Hello, fork()!
 */