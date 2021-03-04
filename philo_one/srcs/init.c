/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:18:45 by youlee            #+#    #+#             */
/*   Updated: 2021/03/04 21:18:48 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int         init_thread(t_philo *in, pthread_t *ph,
        pthread_mutex_t **mu2)
{
    int                 index;
    pthread_mutex_t     *mu;

    mu = *mu2;
    if (!(ph = (pthread_t*)malloc(sizeof(pthread_t) *
    in->number_of_philo)))
        return (show_error("Error: Thread malloc error!\n"));
    index = 0;
    while (index < in->number_of_philo)
    {
        in->id = index;
        in->mutex_left = &mu[index];
        if (index + 1 == in->number_of_philo)
            in->mutex_right = &mu[0];
        else
            in->mutex_right = &mu[index + 1];
        index++;
    }
    return(1);
}
int         init_mutex(t_philo *in, pthread_mutex_t **mu2)
{
    int     index;
    pthread_mutex_t *mu;

    mu = *mu2;
    if (!(mu = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t) *
    in->number_of_philo)))
        return (show_error("Error: Mutex malloc error!\n"));
    index = 0;
    while (index < in->number_of_philo)
        pthread_mutex_init(&mu[index++], NULL);
    return (1);
}