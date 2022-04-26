#include "header.h"

int	parse_init(t_all *args, int argc, char **argv)
{
	args->p.philo_num = ft_atoi(argv[1]);
	args->p.p_dead = ft_atoi(argv[2]);
	args->p.p_eat = ft_atoi(argv[3]);
	args->p.p_sleep = ft_atoi(argv[4]);
	if (argc == 5)
		args->p.must_eat = 0;
	else
    {
        args->p.must_eat = ft_atoi(argv[5]);
        if (args->p.must_eat <= 0)
			return (0);
    }	
	if(!limits_check(args))
		return (0);
	return (1);
}

int arguments_check(int argc, char **argv)
{
	int index;

	index = 1;
	if(argc < 5 || argc > 6)
		return (0);
	while (argv[index])
	{
		if (!ft_is_digit(argv[index]) || (!ft_atoi(argv[index])))
			return (0);
		index++;
	}
	return (1);
}

int	limits_check(t_all *args)
{
	if (args->p.philo_num < 2 || args->p.philo_num > 200
		|| args->p.p_dead  < 60 || args->p.p_eat < 60
		|| args->p.p_sleep < 60)
		return (0);
	return (1);
}