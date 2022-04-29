#include "header.h"

int protection(t_phil *ph)
{
    int var;

    var = 1;   //1 means the philosopher is alive
    pthread_mutex_lock(&ph->tmp->dead);
    if((ph->tmp->stop) == 1)
           var = 0; //0 means the philosopher is dead
    pthread_mutex_unlock(&ph->tmp->dead);
    return (var);   
}