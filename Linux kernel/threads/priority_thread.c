#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<sched.h>

#define NUM_THREADS 5


void *pthread_priority(void *arg)
{
    int id = *(int*)arg;
    printf("thread %d running\n", id);
    sleep(1); //some works
    printf("thread %d finished\n", id);
    pthread_exit(NULL);
}


int main()
{
    pthread_t threads[NUM_THREADS];
    int thread_id [NUM_THREADS];

    for(int i=0;i<NUM_THREADS;i++){
        thread_id[i] = i;
        pthread_create(&threads[i], NULL, pthread_priority, &thread_id[i]);

#if 1    //Prioritize a single thread  
        if(thread_id[i] ==2) {
            struct sched_param params;
            params.sched_priority = 10;
            if(pthread_setschedparam(threads[2],SCHED_FIFO, &params) != 0)
            {
                 perror("pthread_setschedparam");// error ocuured , because not have the root access
                exit(EXIT_FAILURE);
            }
        }
    }
#else //prioritize all threads
    }
    struct sched_param params;
    params.sched_priority = 10;
    for(int i=0;i<NUM_THREADS;i++){
        pthread_setschedparam(threads[i],SCHED_FIFO, &params);
    }
#endif //#if 0
    for(int i=0;i<NUM_THREADS;i++){
        pthread_join(threads[i], NULL);
    }
    printf("all threads execution is completed\n");
    return 0;
}
