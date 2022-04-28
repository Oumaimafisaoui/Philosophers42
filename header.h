/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 22:34:32 by oufisaou          #+#    #+#             */
/*   Updated: 2022/04/28 23:46:36 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/syscall.h>
# include <fcntl.h>
#include <unistd.h>
# include <sys/time.h>

# define INT_MAX 2147483647	
typedef	pthread_mutex_t	mutex;


typedef struct s_propreties
{
	int philo_num; //number of philosophers
	int p_eat; // time spent on eating
	int p_dead; //time to wait untill dying
	int p_sleep; //time when philosopher is sleeping
	long long start_time; //time when program started
	int stop; //if program should stop
	mutex *forks; //mutexes for forks
	int must_eat; //times when philosopher must eat
	mutex *eat;
	mutex *print;
}t_propreties;

typedef struct s_phil
{
    int id; //id of the philosopher
	int last_eat; //time when philosopher ate last time
 	int num_eat; //number of completed meals
	int finish; //if philosopher is finished
	pthread_t thread; //threads created
	int fork_left; //mutex for left fork
	int fork_right; //mutex for right fork
}t_phil;

typedef struct s_all
{ 
    t_phil *philo;
    t_propreties p;

}t_all;


int	limits_check(t_all *args);

int arguments_check(int argc, char **argv);

int	parse_init(t_all *args, int argc, char **argv);

void	exit_program(int flag);


void	ft_putstr_fd(char *s, int fd);

int ft_atoi(const char *dest);


int	ft_is_digit(char *s);

size_t	ft_strlen(const char *str);

int    mutex_initialize(t_all *all);
int  philo_initialize(t_all *all);

int    philos(t_all *all);

int  philo_initialize(t_all *all);

void *philos_routine(void *arg);
long int	the_time(void);

void	ft_usleep(long int time);

#endif