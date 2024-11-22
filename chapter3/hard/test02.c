#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int value = 5;

int main() {
    fork();
    value += 5;
    printf("Hello fork() %d\n", value);
    fork();
    value += 6;
    printf("Hello fork() %d\n", value);
    fork();
    value += 7;
    printf("Hello fork() %d\n", value);
    return 0;
}