/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 17:11:36 by youlee            #+#    #+#             */
/*   Updated: 2021/03/03 17:11:37 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void pickup(t_philo *pp)
{
  int phil_count;
  //pthread_mutex_t *mu = (pthread_mutex_t*)pp->_mutex;

  phil_count = pp->number_philo;

  printf("mutex lock %d %d\n",pp->id, pp->id + 1);
  //pthread_mutex_lock(&mu[pp->id]);       /* lock up left stick */
  //pthread_mutex_lock(&mu[pp->id + 1]); /* lock up right stick */
}

void putdown(t_philo *pp)
{
  int phil_count;
  //pthread_mutex_t *mu = (pthread_mutex_t*)pp->_mutex;

  phil_count = pp->number_philo;
  printf("mutex unlock %d %d\n",pp->id, pp->id + 1);
  //pthread_mutex_unlock(&mu[pp->id]);       /* lock up left stick */
  //pthread_mutex_unlock(&mu[pp->id + 1]); /* lock up right stick */
}

void    *philosopher(void *p)
{
    t_philo     *ph;

    ph = (t_philo*)p;
    while(1)
    {
        printf("philo[%d] thiking!\n", ph->id);
        usleep(ph->ms_sleep);
        printf("philo[%d] eating!\n", ph->id);
        pickup(ph);
        usleep(ph->ms_sleep);
        putdown(ph);
        usleep(ph->ms_sleep);
    }
}

int     main_process(t_philo *in, pthread_t *ph)
{
    t_philo     *ph2;
    int         index;

    if (!(ph = (t_philo*)malloc(sizeof(*ph) * in.number_of_philo)))
        return (show_error("Error: philosopher malloc Error!\n"));
    if (!(ph->_mutex = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t))))
        return (show_error("Error: mutex init Error!\n"));
    index = 0;
    while (index < ph->number_philo)
        pthread_mutex_init(&ph->_mutex[index++], NULL);
    index = 0;
    while (index < in.number_of_philo)
    {
        ph[index].id = index;
        pthread_create(&ph[index].philo, NULL, philosopher,
        (void*)(ph + index));
        index++;
    }
    return (1);
}