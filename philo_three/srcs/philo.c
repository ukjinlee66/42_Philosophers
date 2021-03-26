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

void    *philosopher(t_philo *ph, t_data *data)
{
    pthread_t   mon;
    int         cnt;

    cnt = 0;
    ph->data = data;
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
    if (!ph->live)
      exit(1);
    if (ph->end_eat && cnt == ph->end_eat_amount)
    {
      ph->data->meals++;
      printf("data -> melas : %d\n",ph->data->meals);
    }
    exit(1);
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
  while (!in->data->stop && (in->data->meals) < end)
    sleep_time(1);
  if (in->data->stop || in->data->meals == end)
    delete_philo(end, &in);
  if (!in->data->stop && in->data->meals == end)
  {
    sem_wait(in->mon);
    printf("philo all ate!\n");
  }
}

void    check_die(t_philo *in)
{
  int end;

  end = in[0].number_of_philo;
  while (!in->data->stop)
    sleep_time(10);
  if (in->data->stop)
    delete_philo(end, &in);
}

int     main_process(t_philo *in, t_data *data)
{
    int         index;

    index = 0;
    while (index < in->number_of_philo)
    {
      in[index].pid = fork();
      if (in[index].pid == 0)
        philosopher(&in[index], data);
      index++;
    }
    if (in->end_eat)
      check_meals(in);
    else
      check_die(in);
    return (1);
}
