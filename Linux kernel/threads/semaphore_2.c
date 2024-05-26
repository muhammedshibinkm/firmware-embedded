#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_RESOURCES 3

sem_t semaphore;
int shared_resource = 0;

void* thread_function(void* arg) {
    sem_wait(&semaphore);  // Decrement the semaphore
    // Critical section
    shared_resource++;
    printf("Shared resource: %d\n", shared_resource);
    shared_resource--;
    sem_post(&semaphore);  // Increment the semaphore
    return NULL;
}

int main() {
    pthread_t thread1, thread2, thread3, thread4;

    sem_init(&semaphore, 0, MAX_RESOURCES);

    pthread_create(&thread1, NULL, thread_function, NULL);
    pthread_create(&thread2, NULL, thread_function, NULL);
    pthread_create(&thread3, NULL, thread_function, NULL);
    pthread_create(&thread4, NULL, thread_function, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);

    sem_destroy(&semaphore);
    return 0;
}

}
