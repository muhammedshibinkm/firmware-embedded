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
    int policy;
    pthread_t thread1,thread2;
    pthread_attr_t attr;
    int thread_id[2] = {1,2};
    if(pthread_attr_getschedpolicy(&attr, &policy) !=0) {
        fprintf(stderr, "policy get error\n");
    }else {
        if(policy == SCHED_FIFO) {
            printf("SCHED_FIFO\n");
        }else if(policy == SCHED_RR) {
            printf("SCHED_RR\n");
        }else if(policy == SCHED_OTHER) {
            printf("SCHED_OTHER\n");
        }else {
            printf("fault policy\n");
        }
            
    }
    pthread_attr_setschedpolicy(&attr, SCHED_FIFO);
    pthread_create(&thread1, NULL, high_prior, &thread_id[0]);
    pthread_create(&thread2, NULL, low_prior, &thread_id[1]);   
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
}
