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
    t_philo ph;
    t_input in;
	if (ac < 5 || ac > 6)
        return (show_error("Error: bad arguments!\n"));
    if (!parse_in(&in, ac, av))
        return (show_error("Error: bad input amount!\n"));
}
