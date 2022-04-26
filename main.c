#include "header.h"

int main(int argc, char **argv)
{
    t_all all;
    if(!arguments_check(argc, argv))
        exit_program(1);
    if(!parse_init(&all, argc, argv))
        exit_program(2);
    all.philo = malloc(sizeof(t_phil) * all.p.philo_num);
    if(!all.philo)
        exit_program(3);
    all.p.forks = malloc(sizeof(mutex) * all.p.philo_num);
    if(!all.p.forks)
        exit_program(4);
    if(!mutex_initialize(&all))
         exit_program(5);
    if(!philos(&all))
        exit_program(6);
    return (0);
}