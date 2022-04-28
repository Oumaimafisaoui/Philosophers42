#include "header.h"

// should create the threads

int    philos(t_all *all)
{
    int index;

    index = 0;
    all->p.start_time = the_time(); 
    all->p.stop = 0;
    all->philo = malloc(sizeof(t_phil) * all->p.philo_num);
    if(!all->philo)
    {
        free(all->p.forks);
        return (0);
    }
    while (index < all->p.philo_num)
    {
        all->philo[index].id = index;
        all->philo[index].last_eat = all->p.start_time;
        all->philo[index].num_eat = 0;
        all->philo[index].finish = 0;
		all->philo[index].fork_left = \
		 &all->p.forks[all->philo[index].id];
		all->philo[index].fork_right = \ 
		&all->p.forks[(all->philo[index].id + 1) % all->p.philo_num];
        pthread_create(&all->philo[index].thread, NULL, &philos_thread, &all->philo[index]);
        index++;
    }
	return(1);
}

// void *philos_thread(void *arg)
// {
//      t_all *phil;

//     phil->philo = (t_phil *)arg;
//     if(phil->id % 2 == 1)
//         think(phil, phil->p.p_eat);
//     while(!phil->p.stop)
//     {
//         if(phil->id % 2 == 0)
//             think(phil, phil->p.p_eat);
//         else
//             eat(phil, phil->p.p_eat);
//     }




// }


