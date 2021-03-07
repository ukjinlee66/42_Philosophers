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
    printf("philo[%d] take fork!\n", ph->id);
}

void        philo_eat(t_philo *ph)
{
    printf("philo[%d] eating!\n", ph->id);
    usleep(ph->time_to_eat);
    pthread_mutex_unlock(ph->mutex_left);
    pthread_mutex_unlock(ph->mutex_right);
}

void        philo_sleep(t_philo *ph)
{
    printf("philo[%d] sleep!\n", ph->id);
    usleep(ph->time_to_sleep);
}

void        philo_think(t_philo *ph)
{
    printf("current think time : %d\n",ph->mytime.tv_usec);
}
