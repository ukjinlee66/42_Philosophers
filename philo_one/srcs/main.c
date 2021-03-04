/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:42:01 by youlee            #+#    #+#             */
/*   Updated: 2021/03/02 15:14:03 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    t_philo             in;
    pthread_t           *th;
    pthread_mutex_t     *_mutex;

	if (ac < 5 || ac > 6)
        return (show_error("Error: bad arguments!\n"));
    if (ft_atoi(av[1]) < 2)
        return (show_error("Error: signle philo!\n"));
    if (!parse_in(&in, ac, av))
        return (show_error("Error: bad input amount!\n"));
    if (!init_mutex(&in, &_mutex))
        return (show_error("Error: Not init mutex!\n"));
    if (!init_thread(&in, &th))
        return (show_error("Error: Not init thread!\n"));
    if (!main_process(&in, &th))
        return (show_error("Error: main process!\n"));
    clear_program(&in, th);
    return (0);
}
