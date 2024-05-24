#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>


#define NUM_THREADS 5
#define NUM_RESOURCES 3

sem_t counter_semaphore;

int resource[NUM_RESOURCES];

void *test_semaphore(void *arg) {
    int thread_id = *(int*)arg;
    sem_wait(&counter_semaphore);
    int resource_index = -1;
    for(int i=0;i<NUM_RESOURCES;i++)
    {
        if(resource[i] == 0) {
            resource_index = i;
            resource[i] = thread_id+1;
            break;
        }
    }
    if(resource_index !=-1){
        printf("thread[%d] uses resource[%d]\n",thread_id,resource_index);
        sleep(1);
        printf("Thread %d released resource %d\n", thread_id, resource_index);
        resource[resource_index] = 0; 
    }
    else{
        printf("all resources are occupied, thread %d not find the resources\n",thread_id);
    }
    sem_post(&counter_semaphore);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    sem_init(&counter_semaphore, 0, NUM_RESOURCES);
   // pshared: Specifies whether the semaphore should be shared between processes or threads. If pshared is non-zero, 
   // the semaphore will be shared between processes; otherwise, it will be shared between threads of the same process.
    for(int i=0;i<NUM_THREADS;i++)
    {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, test_semaphore, &thread_ids[i]);
    }

    for(int i=0;i<NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }
    sem_destroy(&counter_semaphore);
    return 0;
}
