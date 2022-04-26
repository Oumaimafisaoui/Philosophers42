#include "header.h"

void    mutex_initialize(t_all *all)
{
    int index;

    index = 0;
    while (i < all->p.philo_num)
    {
        pthread_mutex_init(&all->p.forks[i], NULL);
        i++;
    }
}

