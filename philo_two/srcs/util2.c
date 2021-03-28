/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 23:11:16 by youlee            #+#    #+#             */
/*   Updated: 2021/03/19 23:11:23 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_time(long long delay)
{
	long long purpose;

	purpose = get_time() + delay;
	while (purpose > get_time())
		usleep(10);
}
