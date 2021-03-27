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

void    sleep_time(long long delay)
{
    long long   purpose;

    purpose = get_time() + delay;
    while (purpose > get_time())
        usleep(10);
}

int     wait_status(t_philo *in, int *end, int i)
{
    int         status;

    status = 0;
    waitpid(in[i].pid, &status, WNOHANG);
    if (WIFEXITED(status))
    {
        if (WEXITSTATUS(status) == 4)
            return (4);
        else if (WEXITSTATUS(status) == 3)
        {
            *end = *end + 1;
            if (*end == in[0].number_of_philo)
                return (3);
        }
    }
    return (0);
}

void	check_die_meals(t_philo *in)
{
    int         idx;
    int         end;
    int         status;

    idx = 0;
    end = 0;
    while (idx < in[0].number_of_philo)
    {
        status = wait_status(in, &end, idx);
        if (status == 3 || status == 4)
            break ;
        idx++;
        if (idx == in[0].number_of_philo)
            idx = 0;
    }
    delete_philo(in[0].number_of_philo, &in);
    if (status == 3)
        printf("philo all ate!\n");
}