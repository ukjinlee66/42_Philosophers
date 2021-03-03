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

void    *philosopher(void *p)
{
    t_philo     *ph;

    ph = (t_philo*)p;
    while(1)
    {
        
    }
}

int     main_process(t_input in, int ac, char **av)
{
    t_philo     *ph;
    int         index;

    if (!(ph = (t_philo*)malloc(sizeof(*ph) * in.number_of_philo)))
        return (show_error("Error: philosopher malloc Error!\n"));
    index = 0;
    while (index < in.number_of_philo)
    {
        ph[index].id = index;
        pthread_create(ph[index].philo, NULL, philosopher,
        (void*)(ph + index));
        pthread_mutex_init(&ph[index].mutex_lock, NULL);
    }
}