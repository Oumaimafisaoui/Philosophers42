// #include "header.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static pthread_mutex_t lock;

#define MAX 3
#define MAXT 10
long long i = 0;

void *funct1(void *arg)
{
   
for(;;)
{
    pthread_mutex_lock(&lock);
    
    if (i >= MAXT)
    {
        pthread_mutex_unlock(&lock);
        return (NULL);
    
    }
    ++i;
    pthread_mutex_unlock(&lock);
    printf("\033[0;32m i = %lld \033[0m\n", i);
 }
    
}

int main(void)
{

    int i = 0;

    pthread_t *t = malloc(sizeof(pthread_t) * MAX);

    for(i = 0; i < MAX; ++i)
    {
        pthread_create(&t[i], NULL, funct1, NULL);
    }

    for(i = 0; i < MAX; ++i)
    {
        pthread_join(t[i], NULL);
    }
    return (EXIT_SUCCESS);
}