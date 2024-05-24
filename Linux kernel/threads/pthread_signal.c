#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *arg) {
    // Infinite loop
    while (1) {
        printf("Thread is running...\n");
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t tid;
    int ret;

    // Create a new thread
    ret = pthread_create(&tid, NULL, thread_function, NULL);
    if (ret != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    // Sleep for a while to allow the thread to start
    sleep(3);

    // Send cancellation request to the thread using pthread_kill
    ret = pthread_kill(tid, SIGUSR1);
    if (ret != 0) {
        perror("pthread_kill");
        exit(EXIT_FAILURE);
    }
    
    // Wait for the thread to terminate
    ret = pthread_join(tid, NULL);
    if (ret != 0) {
        perror("pthread_join");
        exit(EXIT_FAILURE);
    }

    printf("Thread terminated successfully.\n");
    return 0;
}
