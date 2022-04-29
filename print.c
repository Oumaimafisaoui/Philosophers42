/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 02:26:15 by oufisaou          #+#    #+#             */
/*   Updated: 2022/04/29 02:39:39 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print(char *str, t_all *all)
{
	pthread_mutex_lock(&all->p.print);
	while(!all->p.stop)
	{
		printf("%lld", the_time() - all->p.start_time);
		printf("            ");
		printf("%d", all->philo->id);
		printf("%s", str);
	}
	pthread_mutex_unlock(&all->p.print);
	exit(1);
}