#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int counter;
pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_fn(void *arg) {
    int id = *(int*)arg;
    pthread_t thread_actual_id = pthread_self();
    pthread_mutex_lock(&counter_mutex);
    printf("mutex locked,for thread_id[%d:%lu],process_id[%d]\n",id, thread_actual_id, getpid());
    counter++;
    pthread_mutex_unlock(&counter_mutex);
    printf("mutex locked\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[2];
    int thread_id[2] ={1,2};
    for(int i=0;i<2;i++) {
        pthread_create(&threads[i], NULL, thread_fn, &thread_id[i]);
    }
    for(int i=0;i<2;i++){
        pthread_join(threads[i], NULL);
    }
}
