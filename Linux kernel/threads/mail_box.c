/*Mail box is a form of inter process communication, where one thread or process can send data into other,it's works
like message queue, thread 1 putting data in queue,other thread can retrieve it.*/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>

#define MAX_MESSAGES 10
#define MESSAGE_SIZE 50

typedef struct {
    char messages[MAX_MESSAGES][MESSAGE_SIZE];
    int count;
    pthread_mutex_t mutex;
    pthread_cond_t not_full;
    pthread_cond_t not_empty;
}Mailbox;

void init_mailbox(Mailbox *mailbox)
{
    mailbox->count = 0;
    pthread_mutex_init(&mailbox->mutex, NULL);
    pthread_cond_init(&mailbox->not_full, NULL);
    pthread_cond_init(&mailbox->not_empty, NULL);
}

void mailbox_send(Mailbox *mailbox, const char *message)
{
    pthread_mutex_lock(&mailbox->mutex);
    while(mailbox->count >=MAX_MESSAGES){
        pthread_cond_wait(&mailbox->not_full, &mailbox->mutex);
    }
    strncpy(mailbox->messages[mailbox->count],message, MESSAGE_SIZE-1);
    mailbox->messages[mailbox->count][MESSAGE_SIZE-1] = '\0';
    mailbox->count++;
    pthread_cond_signal(&mailbox->not_empty);
    pthread_mutex_unlock(&mailbox->mutex);
}

void mailbox_recieve(Mailbox *mailbox,char *message)
{
    pthread_mutex_lock(&mailbox->mutex);
    while(mailbox->count<=0)
    {
        pthread_cond_wait(&mailbox->not_empty,&mailbox->mutex);
    }
    strncpy(message, mailbox->messages[mailbox->count - 1], MESSAGE_SIZE);
    mailbox->count--;
    pthread_cond_signal(&mailbox->not_full);
    pthread_mutex_unlock(&mailbox->mutex);
}


void *producer(void * arg)
{
    Mailbox *mailbox = (Mailbox *)arg;
    for(int i=0;i<20;i++){
        char message[MESSAGE_SIZE];
        snprintf(message, MESSAGE_SIZE, "the message %d from producer\n",i);
        mailbox_send(mailbox,message);
        printf("producer send message %d\n",i);
        usleep(500000);//0.5sec sleep
    }
    return NULL;
}

void *consumer(void *arg)
{
    Mailbox *mailbox = (Mailbox *)arg;
    for(int i=0;i<20;i++)
    {
        char message[MESSAGE_SIZE];
        mailbox_recieve(mailbox,message);
        printf("consumer::%s\n",message);
        usleep(700000);//07sec sleep
    }
    pthread_exit(NULL);
}

int main()
{
    Mailbox mailbox;
    init_mailbox(&mailbox);

    pthread_t threads[2];
    pthread_create(&threads[0], NULL, producer,(void *) &mailbox);
    pthread_create(&threads[1], NULL, consumer,(void *) &mailbox);

    for(int i=0;i<2;i++)
    {
        pthread_join(threads[i], NULL);
    }
    return 0;

}
