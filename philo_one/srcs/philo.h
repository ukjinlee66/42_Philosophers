/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:41:54 by youlee            #+#    #+#             */
/*   Updated: 2021/03/02 15:36:06 by youlee           ###   ########.fr       */
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

# define				PHILO_NUM	2

/*
**	VARIABLE
*/

struct timeval			g_mytime;
typedef struct			s_philo
{
	int					id;
	int					number_philo;
	int					ms_sleep;
	int					status;
	void				*_mutex;
	pthread_t			philo;
}						t_philo;

typedef struct			s_input
{
	int					number_of_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	bool				end_eat;
	int					end_eat_amount;
}						t_input;

/*
**	srcs/util.c
*/

int						ft_strlen(char const *str);
int						show_error(char const *str);
int						ft_atoi(const char *str);

/*
**	srcs/parse.c
*/

int         			parse_in(t_input *input, int ac,
char **av);

/*
**	srcs/philo.c
*/

int						main_process(t_input in, int ac,
char **av);
void					*philosopher(void *p);
void 					pickup(t_philo *pp);
void 					putdown(t_philo *pp);
#endif
