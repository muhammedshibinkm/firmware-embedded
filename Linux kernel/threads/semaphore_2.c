#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_THREADS 5
#define NUM_RESOURCES 3

int resources[NUM_RESOURCES]; // Array to represent the shared resources
sem_t counter_semaphore;

void *worker(void *arg) {
    int thread_id = *((int *)arg);

    // Acquire a permit from the semaphore
    sem_wait(&counter_semaphore);
    
    // Find an available resource
    int resource_index = -1;
    for (int i = 0; i < NUM_RESOURCES; ++i) {
        if (resources[i] == 0) {
            resource_index = i;
            resources[i] = thread_id + 1; // Mark the resource as occupied by the thread
            break;
        }
    }

    if (resource_index != -1) {
        printf("Thread %d is using resource %d\n", thread_id, resource_index);
        // Simulate some work
        sleep(1);
        printf("Thread %d released resource %d\n", thread_id, resource_index);
        resources[resource_index] = 0; // Release the resource
    } else {
        printf("Thread %d couldn't find an available resource\n", thread_id);
    }

    // Release the permit back to the semaphore
    sem_post(&counter_semaphore);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Initialize the counter semaphore with the number of resources
    sem_init(&counter_semaphore, 0, NUM_RESOURCES);

    // Create threads
    for (int i = 0; i < NUM_THREADS; ++i) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, worker, &thread_ids[i]);
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the semaphore
    sem_destroy(&counter_semaphore);

    return 0;
}
