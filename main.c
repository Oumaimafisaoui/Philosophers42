/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 02:06:55 by oufisaou          #+#    #+#             */
/*   Updated: 2022/04/29 05:00:36 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"

int main(int argc, char **argv)
{
    t_all all;
	int index;

	index = 0;
    if(!arguments_check(argc, argv))
        exit_program(1);
    if(!parse_init(&all, argc, argv))
        exit_program(2);
    if(mutex_initialize(&all))
         exit_program(5);
	if(!philo_initialize(&all))
		exit_program(6);
	end_all(&all);
    return (0);
}