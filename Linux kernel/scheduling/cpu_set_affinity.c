
#define _GNU_SOURCE
#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <pthread.h>
#include<sched.h>

void *high_prior(void *arg)
{
    int id = *(int *)arg;
    for(int i=0;i<10;i++)
    {
        printf("thread:%d is executing, executing :%d\n",id, i);
        sleep(1);
    }
    pthread_exit(NULL);
}
void *low_prior(void *arg)
{
    int id = *(int *)arg;
    for(int i=0;i<10;i++)
    {
        printf("thread:%d is executing, executing :%d\n",id, i );
        sleep(2);
    }
    pthread_exit(NULL);
}

void main(void)
{
    int scope;
    pthread_t thread1,thread2;
    int thread_id[2] = {1,2};
    cpu_set_t cpu_set;
    CPU_ZERO(&cpu_set);
    CPU_SET(0, &cpu_set);
    if(pthread_setaffinity_np(thread1, sizeof(cpu_set_t), &cpu_set) !=0) {
        perror("Affinity set error\n");
        exit(EXIT_FAILURE);
    }

    pthread_create(&thread1, NULL, high_prior, &thread_id[0]);
    pthread_create(&thread2, NULL, low_prior, &thread_id[1]);   
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
}
