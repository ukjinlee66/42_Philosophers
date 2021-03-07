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

    printf("assign before\n");
    ph = (t_philo *)p;
    printf("assign after\n");
    while(1)
    {
        gettimeofday(&ph->mytime, NULL);
        printf("current time : %d\n",ph->mytime.tv_usec);
        philo_fork(ph);
        philo_eat(ph);
        philo_sleep(ph);
        philo_think(ph);
    }
    return (NULL);
}

int     main_process(t_philo *in, pthread_t **ph2)
{
    int         index;

    index = 0;
    while (index < in->number_of_philo)
    {
      printf("pthread create %d\n",index);
      if (pthread_create(&(*ph2[index]), NULL, &philosopher, &in[index]))
        return (0);
      index++;
    }
    return (1);
}
