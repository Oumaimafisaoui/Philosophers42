/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:27:57 by oufisaou          #+#    #+#             */
/*   Updated: 2022/04/29 01:25:53 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"

int    philos(t_all *all)
{
    int index;
	void *void_philo;

    index = 0;
    while (index < all->p.philo_num)
    {
		void_philo = (void *)&(all->philo[index]);
        all->philo[index].id = index;
        all->philo[index].last_eat = all->p.start_time;
        all->philo[index].num_eat = 0;
        all->philo[index].finish = 0;
		all->philo[index].fork_left = index;
		all->philo[index].fork_right = (index + 1) % all->p.philo_num;
        if(pthread_create(&all->philo[index].thread, NULL, &philos_routine, NULL)) //add last param
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
	if (!philos(all))
	{
		free(all->philo);
		return (0);
	}

	while(index < all->p.philo_num)
	{
		pthread_join(all->philo[index].thread, NULL);
		index++;
	}
	return (1);
}

void *philos_routine(void *arg)
 {
	// t_all *all;
	// t_phil *philo_two;

	// philo_two = (t_phil *)arg;
	// all->philo = philo_two;
	int i;
	i = 0;
	for(;;)
{
    if (i >= 10)
    {

        return (NULL);
    
    }
    ++i;
    printf("\033[0;32m i = %d\033[0m\n", i);
 }
	
	
}


