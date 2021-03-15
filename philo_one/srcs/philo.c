/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 21:42:47 by youlee            #+#    #+#             */
/*   Updated: 2021/03/07 21:42:50 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void pickup(t_philo *pp)
{
  printf("mutex lock %d %d\n",pp->id, pp->id + 1);
  pthread_mutex_lock(pp->mutex_left);       /* lock up left stick */
  pthread_mutex_lock(pp->mutex_right); /* lock up right stick */
}

void putdown(t_philo *pp)
{
  printf("mutex unlock %d %d\n",pp->id, pp->id + 1);
  pthread_mutex_unlock(pp->mutex_left);       /* lock up left stick */
  pthread_mutex_unlock(pp->mutex_right); /* lock up right stick */
}

void    *philosopher(void *p)
{
    t_philo     *ph;
    pthread_t   mon;
    int         cnt;

    cnt = 0;
    ph = (t_philo *)p;
    printf("current time : %lld\n ph id : %d\n", get_time(),ph->id);
    if (ph->id % 2 != 0)
        usleep(ph->time_to_eat);
    while(ph->live || (ph->end_eat && cnt < ph->end_eat_amount))
    {
        pthread_create(&mon, NULL, &monitor, (void*)ph);
        pthread_detach(mon);
        philo_fork(ph);
        philo_eat(ph);
        philo_sleep(ph);
        philo_think(ph);
        cnt++;
    }
    ph->live = false;
    pthread_detach(mon);
    return (NULL);
}

int     main_process(t_philo *in, pthread_t **ph2)
{
    int         index;

    index = 0;
    while (index < in->number_of_philo)
    {
      printf("pthread create %d\n",index);
      pthread_create(&((*ph2)[index]), NULL, philosopher, (void*)&(in[index]));
      usleep(10);
      index++;
    }
    index = 0;
    return (1);
}
