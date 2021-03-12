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
    in->number_of_philo)))
        return (show_error("Error: Thread malloc error!\n"));
    index = 0;
    while (index < in->number_of_philo)
    {
        in->id = index;
        in->mutex_left = &(*mu2)[index];
        in->time = get_time();
        if (index + 1 == in->number_of_philo)
            in->mutex_right = &(*mu2)[0];
        else
            in->mutex_right = &(*mu2)[index + 1];
		in->live = true;
        in->last_eat_time = 0;
        printf("in -> id : %d\n",in->id);
        index++;
    }
    *ph2 = ph;
    return(1);
}
int         init_mutex(t_philo *in, pthread_mutex_t **mu2)
{
    int                 index;
    pthread_mutex_t     *monitor;

    if (!((*mu2) = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t) *
    in[0].number_of_philo)))
        return (show_error("Error: Mutex malloc error!\n"));
    if (!(monitor = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t))))
        return (show_error("Error: Mutex monitor malloc error!\n"));
    index = 0;
    pthread_mutex_init(monitor, NULL);
    while (index < in[0].number_of_philo)
    {
        pthread_mutex_init(&(*mu2)[index], NULL);
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
    while (index < (*in)->number_of_philo)
        pthread_join((*ph2)[index++], NULL);
    index = 0;
    while (index < (*in)->number_of_philo)
        pthread_mutex_destroy(&(*mu2)[index++]);
    index = 0;
    while (index < (*in)->number_of_philo)
    {
        free(&(*mu2)[index]);
        free(&(*ph2)[index]);
        index++;
    }
    free((*mu2));
    free((*ph2));
    index = 0;
    end = (*in)->number_of_philo;
    while (index < end)
        free(&(*in)[index++]);
    free((*in));
}