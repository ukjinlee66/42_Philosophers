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
    if (ph->live)
      exit(1);
    if (ph->end_eat && cnt == ph->end_eat_amount)
      g_meals++;
    exit(1);
    return (NULL);
}

void    delete_philo(int end, t_philo **in)
{
  int i;

  i = 0;
  while (i < end)
    kill((*in)[i++].pid, SIGKILL);
}

void    check_meals(t_philo *in)
{
  int idx;
  int end;
  idx = 0;
  end = in[idx].number_of_philo;
  while (!g_stop && (g_meals) < end)
    sleep_time(1);
  if (g_stop || g_meals == end)
    delete_philo(end, &in);
  if (!g_stop && g_meals == end)
  {
    sem_wait(in->mon);
    printf("philo all ate!\n");
  }
}

void    check_die(t_philo *in)
{
  int end;

  end = in[0].number_of_philo;
  while (!g_stop)
    sleep_time(10);
  if (g_stop)
    delete_philo(end, &in);
}

int     main_process(t_philo *in, pthread_t **ph2)
{
    int         index;

    index = 0;
    while (index < in->number_of_philo)
    {
      in[index].pid = fork();
      if (in[index].pid == 0)
        pthread_create(&((*ph2)[index]), NULL, philosopher, (void*)&(in[index]));
      index++;
    }
    if (in->end_eat)
      check_meals(in);
    else
      check_die(in);
    return (1);
}
