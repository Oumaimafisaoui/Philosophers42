/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 02:26:15 by oufisaou          #+#    #+#             */
/*   Updated: 2022/04/29 22:35:09 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print(t_phil *philo, char *str, int flag)
{
	pthread_mutex_lock(&philo->tmp->print);
	if(!philo->tmp->stop)
	{
		printf("[%lld]", the_time() - philo->tmp->start_time);
		printf("            ");
		printf("[%d]           ", philo->id);
		printf("\033[92m%s\033[0m", str);
	}
	pthread_mutex_unlock(&philo->tmp->print);
	if(flag)
		exit(1);
}