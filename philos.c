/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:27:57 by oufisaou          #+#    #+#             */
/*   Updated: 2022/04/29 05:27:06 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"

int    philos(t_all *all)
{
    int index;
	// void *void_philo = all;

    index = 0;
    while (index < all->p.philo_num)
    {
		all->philo[index].tmp = &all->p;
        all->philo[index].id = index;
        all->philo[index].last_eat = all->p.start_time;
        all->philo[index].num_eat = 0;
        all->philo[index].finish = 0;
		all->philo[index].fork_left = index;
		all->philo[index].fork_right = (index + 1) % all->p.philo_num;
        if(pthread_create(&all->philo[index].thread, NULL, &philos_routine, &all->philo[index]))
			return (0);
        index++;
    }
	return(1);
}


int  philo_initialize(t_all *all)
{
	int index = 0;
	
	all->p.start_time = the_time(); 
    all->p.stop = 0;
	all->philo = malloc(sizeof(t_phil) * all->p.philo_num);
    if(!all->philo)
    {
        free(all->p.forks);
        return (0);
    }
	if(philos(all) == -1)
		return (0);
	while(index < all->p.philo_num)
	{
		pthread_join(all->philo[index].thread, NULL);
		index++;
	}
	return (1);
}

void *philos_routine(void *arg)
 {
	 t_phil *philo_two;

	 philo_two = (t_phil *)arg;

	//  if(philo_two->tmp->philo_num == 2)
	//  { 
	// 	 printf("Philosopher %d is thinking\n", philo_two->id);
	// 	 usleep(11111);
	// 	 return (NULL);
	//  }
	if(philo_two->id % 2 == 0)
		ft_usleep(philo_two->tmp->time_eat * 1000);

































	 //printf("%d\n", ((t_phil *)arg)->id);
	//  printf("%d\n", ((t_all *)arg)->p.philo_num);
	//  printf("hello\n");

	// t_all *all;
	// t_phil *philo_two;

	// philo_two = (t_phil *)arg;

	// if(all->p.philo_num == 1)
	// {
	// 	  printf("h\n");
	// 	  return (NULL);
	// }
	// else
	// 	printf("h2\n");
	// if(philo_two->id % 2)
	// 	ft_usleep(10000);
	// while(!all->p.stop)
	// {
	// 	if(!all->p.must_eat)
	// 	{
	// 		pthread_mutex_lock(&all->p.eat);
	// 		all->p.must_eat = 1;
	// 		pthread_mutex_unlock(&all->p.eat);
	// 	}
	// 	if(!all->p.stop)
	// 	{
	// 		pthread_mutex_lock(&all->p.forks[philo_two->fork_left]);
	// 		pthread_mutex_lock(&all->p.forks[philo_two->fork_right]);
	// 		if(!all->p.stop)
	// 		{
	// 			pthread_mutex_lock(&all->p.eat);
	// 			all->p.must_eat--;
	// 			pthread_mutex_unlock(&all->p.eat);
	// 			philo_two->num_eat++;
	// 			philo_two->last_eat = the_time();
	// 			pthread_mutex_unlock(&all->p.forks[philo_two->fork_left]);
	// 			pthread_mutex_unlock(&all->p.forks[philo_two->fork_right]);
	// 		}
	// 	}
	// }
	return (NULL);
}


