#include "header.h"


// should initialize the mutexes
int    mutex_initialize(t_all *all)
{
    int index;

    all->p.forks = malloc(sizeof(mutex) * all->p.philo_num);
    if(!all->p.forks)
        return (0);
	index = 0;
    while(index < all->p.philo_num)
    {
        if(pthread_mutex_init(&all->p.forks[index], NULL))
		{
			free(all->p.forks);
			return (0);
		}
        index++;
    }
	if(pthread_mutex_init(&all->philo->print, NULL))
	{
			free(all->p.forks);
			return (0);
	}
	return (1);
}






  // all->p.start_time = the_time();
    // all->p.stop = 0;
    // all->p.num_finish = 0;
    // while (index < all->p.philo_num)
    // {
    //     pthread_mutex_init(&all->p.forks[index], NULL);
    //     index++;
    // }
    // pthread_mutex_init(&all->p.is_write, NULL);
    // pthread_mutex_init(&all->p.is_dead, NULL);
    // // pthread_mutex_init(&all->p.is_eat, NULL);
    // // pthread_mutex_init(&all->p.is_finish, NULL);
    // index = 0;
    // while (index < all->p.philo_num)
    // {
    //     all->philo[index].id = index + 1;
    //     all->philo[index].must_eat = all->p.start_time;
    //     all->philo[index].num_eat = 0;
    //     all->philo[index].finish = 0;

    // }