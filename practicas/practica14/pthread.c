#include <stdio.h>
#include <pthread.h>

#define NUM_TREADS 20

void *helloWorld(void *p)
{
    int id = (int)p;
    printf("hello world %d\n", id);
    return NULL;
}

int main()
{
    pthread_t threads[NUM_TREADS];
    int i;

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
    }    
    return 0;
}