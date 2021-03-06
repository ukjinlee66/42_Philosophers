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
# define PHILO_H

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
# include <semaphore.h>
# include <signal.h>

/*
**	VARIABLE
*/

typedef struct			s_data
{
	bool				stop;
	int					meals;
}						t_data;

typedef struct			s_philo
{
	int					id;
	int					status;
	pid_t				pid;
	sem_t				*fork;
	sem_t				*mon;
	int					number_of_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	bool				end_eat;
	int					end_eat_amount;
	int					eat_amount;
	int					meals;
	bool				live;
	long long			last_eat_time;
	long long			time;
	struct s_data		*data;
}						t_philo;

/*
**	srcs/util.c
*/

int						ft_strlen(char const *str);
int						show_error(char const *str);
int						ft_atoi(const char *str);
long long				get_time(void);

/*
**	srcs/util2.c
*/

void					sleep_time(long long delay);
void					check_die_meals(t_philo *in);
int						wait_status(t_philo *in, int *end, int i);
/*
**	srcs/parse.c
*/

int						parse_in(t_philo **input2, int ac,
		char **av);

/*
**	srcs/philo.c
*/

int						main_process(t_philo *in, t_data *data);
void					*philosopher(t_philo *ph);
void					check_die(t_philo *in);
void					check_meals(t_philo *in);
void					delete_philo(int end, t_philo **in);

/*
**	srcs/philo_action.c
*/

void					philo_fork(t_philo *ph);
void					philo_eat(t_philo *ph);
void					philo_sleep(t_philo *ph);
void					philo_think(t_philo *ph);
void					*monitor(void *p);

/*
**	srcs/init.c
*/

int						init_thread(t_philo *in);
void					clear_program(t_philo **in, t_data **data);
void					init_data(t_data *data);
#endif
