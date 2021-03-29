/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 21:43:27 by youlee            #+#    #+#             */
/*   Updated: 2021/03/07 21:43:30 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	parse_in2(t_philo **input2, int j, int *i, char **av)
{
	(*input2)[j].number_of_philo = ft_atoi(av[(*i)++]);
	(*input2)[j].time_to_die = ft_atoi(av[(*i)++]);
	(*input2)[j].time_to_eat = ft_atoi(av[(*i)++]);
	(*input2)[j].time_to_sleep = ft_atoi(av[(*i)++]);
	(*input2)[j].live = true;
	(*input2)[j].last_eat_time = get_time();
	(*input2)[j].meals = 0;
	(*input2)[j].time = get_time();
}

int			parse_in(t_philo **input2, int ac, char **av)
{
	int		i;
	int		j;
	t_philo	*input;

	input = *input2;
	if (!(input = (t_philo*)malloc(sizeof(t_philo) * ft_atoi(av[1]))))
		return (show_error("Error: t_philo malloc error!\n"));
	j = 0;
	while (j < ft_atoi(av[1]))
	{
		i = 1;
		parse_in2(&input, j, &i, av);
		if (av[i] && i < ac)
		{
			input[j].end_eat = true;
			input[j].end_eat_amount = ft_atoi(av[i++]);
		}
		if (input[j].number_of_philo <= 0 || input[j].time_to_die <= 0 ||
				input[j].time_to_eat <= 0 || input[j].time_to_sleep <= 0 ||
				(input[j].end_eat && input[j].end_eat_amount <= 0))
			return (show_error("Error: input value!\n"));
		j++;
	}
	*input2 = input;
	return (1);
}
