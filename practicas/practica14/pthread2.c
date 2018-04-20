#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define NUM_TREADS 20

void *helloWorld(void *p)
{
    long id = (long)p;
    char *msg = (char*) malloc(25*sizeof(char));
    sprintf(msg, "hello world %ld\n", id);
    return (void *)msg;
}

int main()
{
    pthread_t threads[NUM_TREADS];
    long i;
    char *msgResult;
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
            (void*)&msgResult);
        printf("%s", msgResult);
        free(msgResult);
    }    
    return 0;
}