/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:38:46 by youlee            #+#    #+#             */
/*   Updated: 2021/03/02 15:39:22 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int			show_error(char const *str)
{
	if (str)
		 write(2, str, ft_strlen(str));
	return (1);
}

int			ft_strlen(char const *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int		ft_isspace2(int ch)
{
	if (ch == ' ' || ch == '\t' || ch == '\n' ||
	ch == '\v' || ch == '\f' || ch == '\r')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int					ans;
	int					idx;
	int					sign;
	unsigned long long	check;

	idx = 0;
	ans = 0;
	check = 0;
	while (ft_isspace2(str[idx]))
		idx++;
	sign = str[idx] == '-' ? -1 : 1;
	if (str[idx] == '-' || str[idx] == '+')
		idx++;
	while (str[idx] && ('9' >= str[idx] && str[idx] >= '0'))
	{
		ans = ans * 10 + (str[idx] - '0');
		if (((check * 10) + (str[idx] - '0')) > LLONG_MAX)
			return (sign == 1 ? -1 : 0);
		check = check * 10 + (str[idx] - '0');
		idx++;
	}
	return (ans * sign);
}