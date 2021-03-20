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

#include "../includes/philo.h"

int         init_thread(t_philo *in, pthread_t **ph2)
{
    int                 index;
    pthread_t           *ph;
    sem_t               *fork2;
    sem_t               *mon2;

    sem_unlink("fork");
    sem_unlink("monitor");
    fork2 = sem_open("fork", O_CREAT | O_EXCL, 0644, in[0].number_of_philo);
    mon2 = sem_open("monitor", O_CREAT | O_EXCL, 0644, 1);
    ph = *ph2;
    if (!(ph = (pthread_t*)malloc(sizeof(pthread_t) *
    in[0].number_of_philo)))
        return (show_error("Error: Thread malloc error!\n"));
    index = 0;
    while (index < in[index].number_of_philo)
    {
        in[index].id = index;
        in[index].fork = fork2;
        in[index].mon = mon2;
        index++;
    }
    *ph2 = ph;
    return(1);
}

void        clear_program(t_philo **in, pthread_t **ph2)
{
    int idx;
    int end;

    idx = 0;
    end = in[0]->number_of_philo;
    while (idx < end)
    {
        sem_close((*in)[idx].fork);
        sem_close((*in)[idx].mon);
        idx++;
    }
    free((*ph2));
    free((*in));
}