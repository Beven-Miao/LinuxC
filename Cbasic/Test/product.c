#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

struct msg
{
    struct msg *next;
    int num;
};

struct msg *head;
struct msg *tail;

pthread_cond_t has_product = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *producer(void *p)
{
    struct msg *mp;

    while(1)
    {
        mp = malloc(sizeof(struct msg));
        mp->num = rand()%1000 +1;
        printf("produce %d\n", mp->num);

        pthread_mutex_lock(&lock);
        
        if(head == NULL)
        {
            head = mp;
            head->next = NULL;
            tail = mp;
        }

        if(head != NULL)
        {  head->next = mp;
           head = mp;
        }
        pthread_mutex_unlock(&lock);
        pthread_cond_signal(&has_product);
        sleep(rand()%5);
    }
}



void *consumer(void *p)
{
    struct msg *mp;
    while(1)
    {
        pthread_mutex_lock(&lock);
        while(tail->next ==NULL)
            pthread_cond_wait(&has_product, &lock);

        //mp = head;


          mp = tail;
          tail = tail->next;
        

        pthread_mutex_unlock(&lock);
        printf("Consum %d\n", mp->num);
        free(mp);
        sleep(rand()%5);
    }

}

int main(int argc, char *argv[])
{
    pthread_t pid, cid;

    srand(time(NULL));
    pthread_create(&pid, NULL, producer, NULL);
    pthread_create(&cid, NULL, consumer, NULL);
    pthread_join(pid, NULL);
    pthread_join(cid, NULL);
    return 0;
}

