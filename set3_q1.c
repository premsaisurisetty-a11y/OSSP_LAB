#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }
    else if (pid == 0) {
        printf("Child process executing ls command:\n");
        fflush(stdout);

        execlp("ls", "ls", "-l", (char *)NULL);

        perror("exec failed");
        exit(1);
    }
    else {
        wait(NULL);
        printf("Parent process: Child completed\n");
    }

    return 0;
}
