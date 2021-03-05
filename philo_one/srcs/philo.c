/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 17:11:36 by youlee            #+#    #+#             */
/*   Updated: 2021/03/05 22:01:59 by youlee           ###   ########.fr       */
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

    ph = (t_philo*)p;
    while(1)
    {
        printf("philo[%d] thiking!\n", ph->id);
        usleep(ph->ms_sleep);
        pickup(ph);
        printf("philo[%d] eating!\n", ph->id);
        usleep(ph->ms_sleep);
        putdown(ph);
        usleep(ph->ms_sleep);
    }
}

int     main_process(t_philo *in, pthread_t *ph)
{
    t_philo     *ph2;
    int         index;

    index = 0;
    while (index < in.number_of_philo)
    {
        pthread_create(&ph[index], NULL, philosopher, (void*)(in + index));
        index++;
    }
    return (1);
}
