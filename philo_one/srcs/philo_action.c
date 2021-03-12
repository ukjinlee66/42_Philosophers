/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 21:43:01 by youlee            #+#    #+#             */
/*   Updated: 2021/03/07 21:43:04 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void        philo_fork(t_philo *ph)
{
    pthread_mutex_lock(ph->mutex_left);
    pthread_mutex_lock(ph->mutex_right);
    printf("%lld_in_ms %d has taken a fork\n",get_time() - ph->time, ph->id);
}

void        philo_eat(t_philo *ph)
{
    ph->last_eat_time = get_time();
    printf("%lld_in_ms %d is eating\n", get_time() - ph->time, ph->id);
    usleep(ph->time_to_eat);
    if (ph->end_eat)
        ph->end_eat_amount++;
    pthread_mutex_unlock(ph->mutex_left);
    pthread_mutex_unlock(ph->mutex_right);
}

void        philo_sleep(t_philo *ph)
{
    printf("%lld_in_ms %d is sleeping\n", get_time() - ph->time, ph->id);
    usleep(ph->time_to_sleep);
}

void        philo_think(t_philo *ph)
{
    printf("%lld_in_ms %d is thinking\n",get_time() - ph->time, ph->id);
}

void        *monitor(void *p)
{
    t_philo     *ph;
    
    ph = (t_philo*)p;
    if (ph->live && get_time() - ph->last_eat_time >= ph->time_to_die)
    {
        pthread_mutex_lock(ph->mutex_monitor);
        ph->live = false;
        pthread_mutex_unlock(ph->mutex_monitor);
    }
    return (NULL);
}