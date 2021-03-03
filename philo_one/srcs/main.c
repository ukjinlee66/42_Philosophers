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
    t_input in;
	if (ac < 5 || ac > 6)
        return (show_error("Error: bad arguments!\n"));
    if (in.number_of_philo < 2) //single philo case
        return (show_error("Error: signle philo!\n"));
    if (!parse_in(&in, ac, av))
        return (show_error("Error: bad input amount!\n"));
    if (!main_process(in, ac, av))
        return (show_error("Error: main process!\n"));
    return (0);
}
