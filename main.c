#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    printf("%d \n", getpid());
    int n;
    printf("inserire numero di processi da creare:\n");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        pid_t pid = fork();

        if (pid == -1)
            exit(-1);

        if (pid == 0) {
            printf("son n%d pid:%d\n", i, getpid());
            printf("father pid:%d\n", getppid());
            return 0;
        }
        wait(NULL);
    }
    return 0;
}
