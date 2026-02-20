#include <pthread.h>
#include <stdio.h>

void *worker(void *arg) {
    printf("HELPER\n");
    return NULL;
}

int main() {
    pthread_t tid;
    pthread_create(&tid, NULL, worker, NULL);

    // This ensures HELPER prints before MAIN
    pthread_join(tid, NULL); 

    printf("MAIN\n");
    return 0;
}
