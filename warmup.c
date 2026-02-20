#include <pthread.h>
    #include <stdio.h>
    #include <unistd.h>
    
    void *hello_func(void *arg) {
        printf("Hello from helper thread! My PID is: %d\n", getpid());
        return NULL;
    }
    
    int main() {
        pthread_t tid;
        pthread_create(&tid, NULL, hello_func, NULL);
        printf("Hello from main thread! My PID is: %d\n", getpid());
        pthread_join(tid, NULL);
        return 0;
    }
