#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int counter;
pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;

void *my_turn(void *arg) {
    int *ptr = (int *)arg;
    for (int i = 0; i < 100; i++) {
        sleep(1);
        pthread_mutex_lock(&counter_mutex); // Lock the mutex before accessing counter
        counter++;
        pthread_mutex_unlock(&counter_mutex); // Unlock the mutex after accessing counter
    }
    pthread_exit(NULL);
}

void *your_turn(void *arg) {
    for (int i = 0; i < 90; i++) {
        sleep(2);
        pthread_mutex_lock(&counter_mutex); // Lock the mutex before accessing counter
        counter--;
        pthread_mutex_unlock(&counter_mutex); // Unlock the mutex after accessing counter
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t new_thread;
    pthread_t new_thread_2;
    int *v = malloc(sizeof(int)); // Dynamically allocate memory for v
    if (v == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    *v = 5; // Initialize v
    pthread_create(&new_thread, NULL, my_turn, v);
    pthread_create(&new_thread_2, NULL, your_turn, NULL);
    pthread_join(new_thread, NULL);
    pthread_join(new_thread_2, NULL);
    printf("[%d]\n", counter);
    free(v); // Free dynamically allocated memory
    return 0;
}
