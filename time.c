#include "header.h"

long int	get_time(long int start)
{
	struct timeval	tp;
	long int		time;

    if (gettimeofday(&tp, NULL) == -1)
		ft_exit("Gettimeofday returned -1\n");
	gettimeofday(&tp, NULL);
	time = tp.tv_sec * 1000 + tp.tv_usec / 1000; //tp_tv_sec is in microseconds ans tp_tv_usec is in seconds
	if (start)
		time -= start;
	return (time);
}


void	ft_usleep(long int time_in_ms)
{
	long int	start_time;

	start_time = 0;
	start_time = actual_time();
	while ((actual_time() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}


