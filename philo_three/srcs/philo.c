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

void    *philosopher(t_philo *ph)
{
    pthread_t   mon;
    int         cnt;

    cnt = 0;
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
      exit(4);
    if (ph->end_eat && cnt == ph->end_eat_amount)
      ph->data->meals++;
    exit(3);
}

void    delete_philo(int end, t_philo **in)
{
  int i;

  i = 0;
  while (i < end)
    kill((*in)[i++].pid, SIGKILL);
}

int     main_process(t_philo *in, t_data *data)
{
    int         index;

    index = 0;
    while (index < in->number_of_philo)
    {
      in[index].pid = fork();
      in[index].data = data;
      if (in[index].pid == 0)
        philosopher(&in[index]);
      index++;
    }
    return (1);
}
