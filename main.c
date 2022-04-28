#include "header.h"

int main(int argc, char **argv)
{
    t_all all;
    if(!arguments_check(argc, argv))
        exit_program(1);
    if(!parse_init(&all, argc, argv))
        exit_program(2);
    if(!mutex_initialize(&all))
         exit_program(5);
	if(!philo_initialize(&all))
		exit_program(6);
    return (0);
}