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

void    *philosopher(void *p)
{
    t_philo     *ph;
    pthread_t   mon;
    int         cnt;

    cnt = 0;
    ph = (t_philo *)p;
    if (ph->id % 2 != 0)
        usleep(ph->time_to_eat);
    while((!g_stop && ph->live) || (ph->end_eat && cnt < ph->end_eat_amount))
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
    int       index2;

    index = 0;
    index2 = 0;
    while (!g_stop && index < in->number_of_philo)
    {
      pthread_create(&((*ph2)[index]), NULL, philosopher, (void*)&(in[index]));
      usleep(10);
      if (g_stop)
      {
        index2 = 0;
        while (index2 < in->number_of_philo)
          pthread_detach((*ph2)[index2++]);
        return (1);
      }
      index++;
    }
    index = 0;
    return (1);
}
