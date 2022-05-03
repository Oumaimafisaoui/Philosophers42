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
	//break ;
    ++i;
	
    pthread_mutex_unlock(&lock);
    printf("\033[0;32m i = %lld \033[0m\n", i);
 }
 return (NULL);
    
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

// void	ft_usleep(long int time)
// {

//     long int    start_time;

//     start_time = 0;
//     start_time = the_time();
//     while ((the_time() - start_time) < time)
//         usleep(time / 10);
// }
// void	eat_time(t_phil *game) //chnage this function
// {
// 	long long	eat_time;
// 	long long	start_e_time;
// 	long long	now_e_time;

// 	eat_time = (long long)(game->tmp->start_time);
// 	start_e_time = the_time();
// 	while (!(game->tmp->stop))
// 	{
// 		now_e_time = the_time();
// 		if ((now_e_time - start_e_time) >= eat_time)
// 			break ;
// 		usleep(10);
// 	}
// }

// void	sleep_time(t_phil *game)
// {
// 	long long	sleep_time;
// 	long long	start_s_time;
// 	long long	now_s_time;

// 	sleep_time = (long long)(game->tmp->p_sleep);
// 	start_s_time = the_time();
// 	while (!(game->tmp->stop))
// 	{
// 		now_s_time = the_time();
// 		if ((now_s_time - start_s_time) >= sleep_time)
// 			break ;
// 		usleep(10); //why break here?
		
// 	}
// }




// void	ft_usleep(long int n)
// {
// 	struct timeval	start;
// 	struct timeval	step;

// 	gettimeofday(&start, NULL);
// 	while (1)
// 	{
// 		usleep(100000);
// 		gettimeofday(&step, NULL);
// 		if (((step.tv_sec - start.tv_sec) * 1000000
// 				+ (step.tv_usec - start.tv_usec)) > n)
// 			break ;
// 		usleep(1000);
// 	}
// }
