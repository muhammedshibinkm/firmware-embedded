#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <pthread.h>
#include <time.h>

#define THREAD_COUNT 10
#define DATA_SIZE 10000000
#define EACH_EXEC_SIZE (DATA_SIZE/10)
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
typedef struct Data {
    long *arr;
    long start_index;
    //int end_index;
    long long sum;
}Data_t;

void init_data(Data_t *data)
{
    for(int i = 0; i < THREAD_COUNT; i++) {
        long *arr1 = (long*)malloc(sizeof(long)*DATA_SIZE);
        if (!arr1) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }
        data[i].arr = arr1;
        data[i].start_index = 0;
        // data->end_index = 0;
        data[i].sum = 0;
    }
}
void *add_i_half(void *arg)
{
    
    Data_t *data = (Data_t*)arg;
    if (data[i].start_index + EACH_EXEC_SIZE > DATA_SIZE) {
            printf("Error: Trying to access beyond array bounds.\n");
            pthread_exit(NULL);
    }
    for(int i = data[i].start_index; i < data[i].start_index+EACH_EXEC_SIZE; i++)
    {
        data[i].sum = data[i].arr[i] + data[i].sum;
    }
    pthread_exit(NULL);
}

int main()
{
    long long sum=0;
    long *arr = (long*)malloc(sizeof(long)*DATA_SIZE);
    if (!arr) {
    perror("Failed to allocate memory");
    exit(EXIT_FAILURE);
    }
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    Data_t data[THREAD_COUNT];
    init_data(data);
    pthread_t thread[THREAD_COUNT];
    for(long i=0;i<DATA_SIZE;i++) {
        arr[i] = i+1;
    }
    for(int i=0;i<THREAD_COUNT;i++) {
        data[i].start_index = (i*EACH_EXEC_SIZE);
        data[i].arr = arr ;//+ (i*EACH_EXEC_SIZE);
        pthread_create(&thread[i], NULL, add_i_half, &data[i]);  
    }
    for(int i=0;i<THREAD_COUNT;i++) {
        pthread_join(thread[i], NULL);
    }
     for(int i = 0; i < THREAD_COUNT; i++) {
       sum =sum+ data[i].sum;
    }
    free(arr);
    printf("sum = %lld\n",sum); 
    clock_gettime(CLOCK_MONOTONIC, &end);
    double time_spent = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1E9;
    printf("Total time spends = %lf\n",time_spent);
    return 0;
    
}
