#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

volatile int val = 20;
volatile int *ptr = &val;
void *vol_check(void *args)
{
    for(int i=0;i<50;i++)
    {
        usleep(5000);
        *ptr = *ptr+i;
    }
    pthread_exit(NULL);
}
void *print_vol(void *args)
{
    for(int i=0;i<20;i++)
    {
        printf("%d\n",*ptr * *ptr);
        usleep(5000);
    }
    pthread_exit(NULL);
}


int main()
{
    pthread_t threads[2];
    pthread_create(&threads[0],NULL, vol_check, NULL);
    pthread_create(&threads[1],NULL, print_vol, NULL);
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    return 0;

}
