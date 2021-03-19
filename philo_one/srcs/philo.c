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
    pthread_create(&mon, NULL, &monitor, (void*)ph);
    pthread_detach(mon);
    while(ph->live && (!ph->end_eat || cnt < ph->end_eat_amount))
    {    
        philo_fork(ph);
        philo_eat(ph);
        philo_sleep(ph);
        philo_think(ph);
        cnt++;
    }
    ph->live = false;
    if (ph->end_eat && cnt == ph->end_eat_amount)
      g_meals++;
    return (NULL);
}

void    delete_philo(int end, pthread_t **ph2)
{
  int i;

  i = 0;
  while (i < end)
    pthread_detach((*ph2)[i++]);
}

void    check_meals(t_philo *in, pthread_t **ph2)
{
  int idx;
  int end;
  idx = 0;
  end = in[idx].number_of_philo;
  while (!g_stop && (g_meals) < end)
    usleep(1);
  if (g_stop || g_meals == end)
    delete_philo(end, ph2);
  if (!g_stop && g_meals == end)
  {
    pthread_mutex_lock(in->mutex_monitor);
    printf("philo all ate!\n");
  }
}

void    check_die(t_philo *in, pthread_t **ph2)
{
  int end;

  end = in[0].number_of_philo;
  while (!g_stop)
    usleep(1);
  if (g_stop)
    delete_philo(end, ph2);
}

int     main_process(t_philo *in, pthread_t **ph2)
{
    int         index;

    index = 0;
    while (index < in->number_of_philo)
    {
      pthread_create(&((*ph2)[index]), NULL, philosopher, (void*)&(in[index]));
      //usleep(10);
      index++;
    }
    if (in->end_eat)
      check_meals(in, ph2);
    else
      check_die(in, ph2);
    return (1);
}
