/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:41:54 by youlee            #+#    #+#             */
/*   Updated: 2021/03/05 21:50:21 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

/*
**	INCLUDES FILES
*/

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <limits.h>

/*
**	Define
*/


/*
**	VARIABLE
*/

struct timeval			g_mytime;
typedef struct			s_philo
{
	int					id;
	int					status;
	pthread_mutex_t		*mutex_left;
	pthread_mutex_t		*mutex_right;
	int					number_of_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	bool				end_eat;
	int					end_eat_amount;
	bool				live;
}						t_philo;

/*
**	srcs/util.c
*/

int						ft_strlen(char const *str);
int						show_error(char const *str);
int						ft_atoi(const char *str);

/*
**	srcs/parse.c
*/

int         			parse_in(t_philo *input, int ac,
char **av);

/*
**	srcs/philo.c
*/

int						main_process(t_philo in, );
void					*philosopher(void *p);
void 					pickup(t_philo *pp);
void 					putdown(t_philo *pp);

/*
**	srcs/init.c
*/

int						init_thread(t_philo *in, pthread_t *ph,
		pthread_mutex_t **mu2);
int						init_mutex(t_philo *in, pthread_mutex_t **mu2);

#endif
