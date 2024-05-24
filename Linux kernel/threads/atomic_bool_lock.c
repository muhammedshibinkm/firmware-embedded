#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdatomic.h>
#include<unistd.h>
#include<pthread.h>


int count;

atomic_bool lock = false;

void acquire_lock() {
	while(atomic_exchange(&lock,true)) {
	}
}      

void release_lock() {
	atomic_store(&lock,false);
}

void *set_loc_fun(void *arg) {
	int thread_id = *(int*)arg;
	acquire_lock();
	printf("the thread[%d] enerted in critical section\n",thread_id);
	//count++;
	sleep(1);
	printf("the thread[%d] exited from critical section\n", thread_id);
	release_lock();
}

int main()
{
	pthread_t thread_new[2];
	int thread_id[2] = {1,2};

	for(int i=0;i<2;i++) {
		pthread_create(&thread_new[i], NULL, set_loc_fun, &thread_id[i]);
	}
        for(int i=0;i<2;i++) {
		pthread_join(thread_new[i], NULL);
	}
	return 0;
}

