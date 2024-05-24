#include <stdio.h>
#include <stdbool.h>
#include <stdatomic.h>
#include <pthread.h>
#include <unistd.h>

atomic_bool lock = false; // Initialize the lock to false (unlocked)

void acquire_lock() {
    while (atomic_exchange(&lock, true)) {
        // Spin until the lock is acquired
    }
}

void release_lock() {
    atomic_store(&lock, false);
}

void *thread_function(void *arg) {
    int thread_id = *(int *)arg;
    
    acquire_lock();
    printf("Thread %d entered the critical section.\n", thread_id);
    sleep(1); // Simulate some work in the critical section
    printf("Thread %d exiting the critical section.\n", thread_id);
    release_lock();
    
    return NULL;
}

int main() {
    pthread_t threads[2];
    int thread_ids[2] = {1, 2};
    
    for (int i = 0; i < 2; ++i) {
        pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
    }
    
    for (int i = 0; i < 2; ++i) {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}
