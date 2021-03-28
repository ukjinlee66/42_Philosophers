/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 21:43:01 by youlee            #+#    #+#             */
/*   Updated: 2021/03/07 21:43:04 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		philo_fork(t_philo *ph)
{
	sem_wait(ph->fork);
	sem_wait(ph->fork);
	sem_wait(ph->mon);
	printf("%lld_in_ms %d has taken a fork\n", get_time() - ph->time, ph->id);
	sem_post(ph->mon);
}

void		philo_eat(t_philo *ph)
{
	sem_wait(ph->mon);
	ph->last_eat_time = get_time();
	printf("%lld_in_ms %d is eating\n", get_time() - ph->time, ph->id);
	sem_post(ph->mon);
	sleep_time(ph->time_to_eat);
	sem_post(ph->fork);
	sem_post(ph->fork);
}

void		philo_sleep(t_philo *ph)
{
	sem_wait(ph->mon);
	printf("%lld_in_ms %d is sleeping\n", get_time() - ph->time, ph->id);
	sem_post(ph->mon);
	sleep_time(ph->time_to_sleep);
}

void		philo_think(t_philo *ph)
{
	sem_wait(ph->mon);
	printf("%lld_in_ms %d is thinking\n", get_time() - ph->time, ph->id);
	sem_post(ph->mon);
}

void		*monitor(void *p)
{
	t_philo		*ph;

	ph = (t_philo*)p;
	while (!g_stop && ph->live)
	{
		if (ph->live && get_time() - ph->last_eat_time > ph->time_to_die)
		{
			sem_wait(ph->mon);
			printf("%lld_in_ms %d died\n", get_time() - ph->time, ph->id);
			g_stop = true;
			ph->live = false;
		}
	}
	ph->live = false;
	return (NULL);
}
