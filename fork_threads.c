#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void *worker(void *arg) {
    // Return 42 as a pointer
    return (void *)42;
}

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // This is the CHILD process
        pthread_t tid;
        void *retval;
        pthread_create(&tid, NULL, worker, NULL);
        pthread_join(tid, &retval);
        printf("Child Process: Thread returned %ld\n", (long)retval);
    } else {
        // This is the PARENT process
        wait(NULL); // Wait for child to finish
        printf("Parent Process: Finished.\n");
    }
    return 0;
}
