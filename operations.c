#include "header.h"

// void    think(t_all *all, int t)
// {
//     if(all->philo->stop)
//         return ;
//     printf("Thinking");
//     if(t)
//         usleep(t);
// }


int	ft_philo_do(t_game *game, t_philo *philo)
{
	pthread_mutex_lock(&(game->forks[philo->left_fork]));
	ft_printf(game, "has taken a fork", philo->id);
	pthread_mutex_lock(&(game->forks[philo->right_fork]));
	ft_printf(game, "has taken a fork", philo->id);
	ft_philo_eat(philo->game, philo);
	pthread_mutex_unlock(&(game->forks[philo->left_fork]));
	pthread_mutex_unlock(&(game->forks[philo->right_fork]));
	if (game->eat_check)
		return (-1);
	return (0);
}


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

