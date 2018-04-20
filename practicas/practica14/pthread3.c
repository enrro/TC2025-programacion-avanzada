#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_TREADS 20

int varglobal;
sem_t sema;

void *helloWorld(void *p)
{
    long id = (long)p;
    printf("hello world %ld\n", id);
    sema_wait(&sema);
    varglobal = id;  
    sema_post(&sema);
    return NULL;
}


int main()
{
    pthread_t threads[NUM_TREADS];
    long i;
    varglobal =0;
    //sem_init(&sema,0,1);
    sema = 1;
    for (i = 0; i < NUM_TREADS; i++)
    {
        pthread_create(
            &threads[i],
            NULL,
            helloWorld,
            (void *)i);
    }
    for (i = 0; i < NUM_TREADS; i++)
    {
        pthread_join(
            threads[i],
            NULL);
        printf("varglobal = %d\n", varglobal);
    }    
    return 0;
}