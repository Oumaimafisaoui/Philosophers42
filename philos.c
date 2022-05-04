/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:27:57 by oufisaou          #+#    #+#             */
/*   Updated: 2022/05/04 17:39:49 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"

int    philos(t_all *all)
{
    int index;
	
    index = 0;
    while (index < all->p.philo_num)
    {
		all->philo[index].tmp = &all->p;
        all->philo[index].id = index;
        all->philo[index].last_eat = the_time();
        all->philo[index].num_eat = 0;
		all->philo[index].fork_left = index;
		all->philo[index].fork_right = (index + 1) % all->p.philo_num;
        if(pthread_create(&all->philo[index].thread, NULL, &philos_routine, &all->philo[index]))
			return (0);
        index++;
    }
	is_dead(all);
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


//all the odd number stop for a while then the even number start eating, in the meanwhile the odd
//numbers start sleeping for the sleeping amount, then thinks or eat if the number of meals is less than the number of meals
//
void *philos_routine(void *arg)
 {
	 t_phil *philo_two;
	 
	philo_two = (t_phil *)arg;
	if(philo_two->id % 2 == 0)
		usleep(10000);
	while(!(philo_two->tmp->stop))
	{
		if(philo_eat(philo_two))
			break ;
		print(philo_two, "is sleeping\n", 0);
		ft_usleep(philo_two->tmp->p_sleep);
		print(philo_two, "is thinking\n", 0);
	}
	//ft_putstr_fd("done!", 1);
	return (NULL);
}
