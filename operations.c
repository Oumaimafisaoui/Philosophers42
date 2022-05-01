#include "header.h"


int philo_eat(t_phil *philo)
{
	if(philo->tmp->philo_num == 1)
	{
		pthread_mutex_lock(&(philo->tmp->forks[philo->fork_left]));
		print(philo, "has taken left fork\n", 0);
		print(philo, "I'm alone, didn't have another fork, I died...\n", 1);
	}	
	pthread_mutex_lock(&(philo->tmp->forks[philo->fork_left]));
	print(philo, "has taken left fork\n", 0);
	pthread_mutex_unlock(&(philo->tmp->forks[philo->fork_left]));
	pthread_mutex_lock(&(philo->tmp->forks[philo->fork_right]));
	print(philo, "has taken right fork\n", 0);
	pthread_mutex_unlock(&(philo->tmp->forks[philo->fork_right]));
	pthread_mutex_lock(&(philo->tmp->eat));
	print(philo, "is eating\n", 0);
	philo->last_eat = the_time();
	pthread_mutex_unlock(&(philo->tmp->eat));
	philo->num_eat++;
	usleep(philo->tmp->p_eat * 1000);
	if(philo->tmp->flag)
		return (1);
	return (0);
}


void  is_dead(t_all *all)
{
	int index;

	while(!(all->p.flag))
	{
		index = 0;
		while(index < all->p.philo_num && (!(all->p.stop)))
		{
			pthread_mutex_lock(&(all->p.eat));
			if((the_time() - all->philo[index].last_eat) > all->p.p_dead)
			{
				print(&all->philo[index], "is dead\n", 0);
				all->p.stop = 1;
			}
			pthread_mutex_unlock(&(all->p.eat));
			index++;
		}
		if(all->p.stop)
			break ;
		check_eat(all);
	}
}



void check_eat(t_all *all)
{
	int index;
	
	index = 0;
	while(all->p.must_eat != 0 && index < all->p.philo_num && all->philo[index].num_eat > all->p.must_eat)
         index++;
	if(index == all->p.philo_num)
		all->p.flag = 1;
}


// void time_sleep(t_propreties *all)
// {
// 	long long sleep;
// 	long long start;
// 	long long now;

// 	start = the_time();
// 	sleep = (long long)(all->p_sleep);
// 	while (!(all->stop))
// 	{
// 		now = the_time();
// 		if(now >= sleep + start)
// 			break ;
// 		usleep(10);
// 	}
	
// }