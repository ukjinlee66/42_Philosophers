/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:05:15 by youlee            #+#    #+#             */
/*   Updated: 2021/03/02 16:05:23 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int         parse_in(t_philo *input, int ac, char **av)
{
    int i;

    i = 1;
    input->number_of_philo = ft_atoi(av[i++]);
    input->time_to_die = ft_atoi(av[i++]);
    input->time_to_eat = ft_atoi(av[i++]);
    input->time_to_sleep = ft_atoi(av[i++]);
    if (av[i] && i < ac)
    {
        input->end_eat = true;
        input->end_eat_amount = ft_atoi(av[i++]);
    }
    if (input->number_of_philo < 0 || input->time_to_die < 0 ||
    input->time_to_eat < 0 || input->time_to_sleep < 0 ||
    (input->end_eat && input->end_eat_amount < 0))
        return (show_error("Error: input value!\n"));
    return (1);
}