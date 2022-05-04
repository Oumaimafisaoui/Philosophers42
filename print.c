/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 02:26:15 by oufisaou          #+#    #+#             */
/*   Updated: 2022/05/04 15:48:13 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print(t_phil *philo, char *str, int flag)
{
	long long time;
	
	time = the_time();
	pthread_mutex_lock(&philo->tmp->print);

	if(!philo->tmp->stop)
	{
		ft_putnbr_fd(time - philo->tmp->start_time, 1);
		ft_putstr_fd("          ", 1);
		ft_putnbr_fd(philo->id, 1);
		ft_putstr_fd("          ", 1);
		ft_putstr_fd(str, 1);
	}
	pthread_mutex_unlock(&philo->tmp->print);
	if(flag)
		exit(1);
}