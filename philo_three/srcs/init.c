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

int         init_thread(t_philo *in)
{
    int                 index;
    sem_t               *fork2;
    sem_t               *mon2;

    sem_unlink("fork");
    sem_unlink("monitor");
    fork2 = sem_open("fork", O_CREAT | O_EXCL, 0644, in[0].number_of_philo);
    mon2 = sem_open("monitor", O_CREAT | O_EXCL, 0644, 1);
    index = 0;
    while (index < in[index].number_of_philo)
    {
        in[index].id = index;
        in[index].fork = fork2;
        in[index].mon = mon2;
        index++;
    }
    return(1);
}

void        init_data(t_data *data)
{
    data->stop = false;
    data->meals = 0;
}

void        clear_program(t_philo **in, t_data **data)
{
    free((*data));
    free((*in));
}