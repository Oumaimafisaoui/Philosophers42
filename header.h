/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 22:34:32 by oufisaou          #+#    #+#             */
/*   Updated: 2022/05/04 15:46:42 by oufisaou         ###   ########.fr       */
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
	mutex eat;
	mutex print;
	mutex dead;
	int flag;
}t_propreties;

typedef struct s_phil
{
    int id; //id of the philosopher 
 	int num_eat; //number of completed meals
	long long last_eat;
	//int finish; //if philosopher is finished
	pthread_t thread; //threads created
	int fork_left; //mutex for left fork
	int fork_right; //mutex for right fork
	t_propreties *tmp;
}t_phil;

typedef struct s_all
{ 
    t_phil *philo;
    t_propreties p;

}t_all;

int protection(t_phil *ph);
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

void time_sleep(t_propreties *all);
long int	the_time(void);

void	end_all(t_all *all);
void	print(t_phil *philo, char *str, int flag);
int philo_eat(t_phil *philo);
void check_eat(t_all *all);
void  is_dead(t_all *all);
void	print_one(t_phil *philo, char *str, int flag);

void	ft_usleep(long n);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
#endif