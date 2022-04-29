#include "header.h"

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

