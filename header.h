#ifndef HEADER_H
# define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/syscall.h>
# include <fcntl.h>
#include <unistd.h>

# define INT_MAX 2147483647	
typedef	pthread_mutex_t	mutex;


typedef struct s_propreties
{
	int philo_num;
	int p_eat;
	int p_dead;
	int p_sleep;
	long long start_time;
	int stop;
	mutex *forks;
	int must_eat;
	

}t_propreties;

typedef struct s_phil
{
	pthread_t thread;
    int id;
    long int last_meal;
    int meal_num;
    int left_fork;
    int right_fork;

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


#endif