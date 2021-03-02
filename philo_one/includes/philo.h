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

/*
**	VARIABLE
*/

struct timeval			g_mytime;
typedef struct			s_philo
{
	int					id;
	int					status;
	pthread_mutex_t		mutex_lock;
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


/*
**	srcs/parse.c
*/

int         			parse_in(t_input *input, int ac, char **av);

#endif
