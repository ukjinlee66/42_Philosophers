/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 21:43:16 by youlee            #+#    #+#             */
/*   Updated: 2021/03/07 21:43:18 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int         init_thread(t_philo *in, pthread_t **ph2,
        pthread_mutex_t **mu2)
{
    int                 index;
    pthread_t           *ph;

    ph = *ph2;
    if (!(ph = (pthread_t*)malloc(sizeof(pthread_t) *
    in[0].number_of_philo)))
        return (show_error("Error: Thread malloc error!\n"));
    index = 0;
    while (index < in[index].number_of_philo)
    {
        in[index].id = index;
        in[index].mutex_left = &(*mu2)[index];
        if (index + 1 == in[index].number_of_philo)
            in[index].mutex_right = &(*mu2)[0];
        else
            in[index].mutex_right = &(*mu2)[index + 1];
		
        index++;
    }
    *ph2 = ph;
    return(1);
}
int         init_mutex(t_philo *in, sem_t **sem2)
{
    int                 index;
    sem_t     *monitor;

    if (!((*sem2) = (sem_t*)malloc(sizeof(sem_t) *
    in[0].number_of_philo)))
        return (show_error("Error: Mutex malloc error!\n"));
    index = 0;
    while (index < in[0].number_of_philo)
    {
        pthread_mutex_init(&(*sem2)[index], NULL);
        in[index].mutex_monitor = monitor;
        index++;
    }
    return (1);
}

void        clear_program(t_philo **in, pthread_mutex_t **mu2,
        pthread_t **ph2)
{
    int     index;
    int     end;

    index = 0;
    end = (*in)[index].number_of_philo;
    index = 0;
    while (index < end)
        pthread_mutex_destroy(&(*mu2)[index++]);
    free((*mu2));
    free((*ph2));
    index = 0;
    pthread_mutex_destroy((*in)->mutex_monitor);
    free((*in));
}