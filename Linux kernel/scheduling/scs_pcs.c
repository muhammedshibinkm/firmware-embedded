
#include <stdio.h>
#include<unistd.h>
#include <pthread.h>

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
    pthread_attr_t thread_attr;
    /*get default attributes*/
    pthread_attr_init(&thread_attr);
    /*first inquire on the current scope*/
    if(pthread_attr_getscope(&thread_attr, &scope) !=0) {
        fprintf(stderr, "Unebale to get scheduling scope\n");
    } else {
        if(scope == PTHREAD_SCOPE_SYSTEM) {
            printf("PTHREAD_SCOPE_SYSTEM\n");
        } else if(scope == PTHREAD_SCOPE_PROCESS) {
            printf("PTHREAD_SCOPE_PROCESS\n");
        } else {
            fprintf(stderr, "undefined scope\n");
        }
    }
    pthread_attr_setscope(&thread_attr, PTHREAD_SCOPE_PROCESS);
    int thread_id[2] = {1,2};
    pthread_create(&thread1, NULL, high_prior, &thread_id[0]);
    pthread_create(&thread2, NULL, low_prior, &thread_id[1]);   
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
}
