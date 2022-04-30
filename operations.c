#include "header.h"


int philo_eat(t_phil *philo)
{
	if(philo->tmp->philo_num == 1)
		print(philo, "I'm alone, didn't have another fork, I died...\n", 1);
	pthread_mutex_lock(&(philo->tmp->forks[philo->fork_left]));
	print(philo, "has taken left fork\n", 0);
	// if(philo->id == philo->tmp->philo_num - 1)
	// 	pthread_mutex_lock(&(philo->tmp->forks[0]));
	// else
	pthread_mutex_lock(&(philo->tmp->forks[philo->fork_right]));
	print(philo, "has taken right fork\n", 0);
	pthread_mutex_lock(&(philo->tmp->eat));
	print(philo, "is eating\n", 0);
	philo->last_eat = the_time();
	pthread_mutex_unlock(&(philo->tmp->eat));
	philo->num_eat++;
	ft_usleep(philo->tmp->p_eat * 1000);
	// if (philo->id == philo->tmp->philo_num)
	// 	pthread_mutex_unlock(&(philo->tmp->forks[0]));
	// else
	pthread_mutex_unlock(&(philo->tmp->forks[philo->fork_left]));
	pthread_mutex_unlock(&(philo->tmp->forks[philo->fork_left]));
	if(philo->tmp->flag)
		return (1);
	return (0);
}
















// void    think(t_all *all, int t)
// {
//     if(all->philo->stop)
//         return ;
//     printf("Thinking");
//     if(t)
//         usleep(t);
// }




// void sleep_p(t_all *all)
// {
//     if(all->philo->stop)
//         return ;
//     printf("Sleeping");
//     usleep(all->p->p_sleep * 1000);
// }

// int	check_death(t_philo *ph, int i)
// {
// 	pthread_mutex_lock(&ph->pa->dead);
// 	if (i)
// 		ph->pa->stop = i;
// 	if (ph->pa->stop)
// 	{
// 		pthread_mutex_unlock(&ph->pa->dead);
// 		return (1);
// 	}
// 	pthread_mutex_unlock(&ph->pa->dead);
// 	return (0);
// }

