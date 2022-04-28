/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 22:36:51 by oufisaou          #+#    #+#             */
/*   Updated: 2022/04/28 23:43:16 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"

long int	the_time(void)
{
	struct timeval	tp;
	long int		time;

    if (gettimeofday(&tp, NULL) == -1)
		exit_program(7);
	gettimeofday(&tp, NULL);
	time = (tp.tv_sec * 1000) + (tp.tv_usec / 1000); //TV_SEC = secondes, TV_USEC = microsecondes , WE WANT MILLISECONDS
	// if (start)
	// 	time -= start;
	return (time);
}
// void	ft_usleep(long int time)
// {
// 	long int	start;

// 	start = 0;
// 	start = the_time();
// 	while ((the_time() - start) < time)
// 		usleep(time / 10);
// }


