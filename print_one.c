/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 22:16:16 by oufisaou          #+#    #+#             */
/*   Updated: 2022/05/04 17:29:51 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


void	print_one(t_phil *philo, char *str, int flag)
{
	long long time;
	
	time = the_time();
	pthread_mutex_lock(&philo->tmp->print);
	
	if(time != philo->tmp->start_time)
	{
		time = philo->tmp->start_time;
	}
	if(!philo->tmp->stop)
	{
		printf("[%lld]", time - philo->tmp->start_time);
		printf("            ");
		printf("[%d]           ", philo->id);
		printf("\033[92m%s\033[0m", str);
	}
	pthread_mutex_unlock(&philo->tmp->print);
	// if(flag)
	// 	exit(1);
}