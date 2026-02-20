#include <pthread.h>
#include <stdio.h>

void *modify_value(void *arg) {
    int *val = (int *)arg;
    *val = 2; // Changes the variable 'i' from main
    return NULL;
}

int main() {
    int i = 1;
    pthread_t tid;
    pthread_create(&tid, NULL, modify_value, &i);
    pthread_join(tid, NULL);
    printf("The value of i is now: %d\n", i);
    return 0;
}
