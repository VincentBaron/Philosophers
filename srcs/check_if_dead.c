/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:41:42 by vbaron            #+#    #+#             */
/*   Updated: 2021/12/07 15:17:26 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int check_if_dead_or_done_eating(t_gen *mother)
{
    int i;
    t_philo *end_philo;
    long eat_time;

    end_philo = NULL;
    while (1)
    {
        i = 0;
        while (i < mother->nb_philos)
        {
            pthread_mutex_lock(&mother->eat_mutex);
            eat_time = mother->philo[i].last_meal;
            pthread_mutex_unlock(&mother->eat_mutex);
            if (get_time() - eat_time > mother->t_die)
            {
                pthread_mutex_lock(&mother->write_mutex);
                mother->can_write = 0;
                pthread_mutex_unlock(&mother->write_mutex);
                end_philo = &mother->philo[i];
                safe_write(end_philo, DEAD);
                return (1);
            }
            i++;
        }
        usleep(10); 
    }
    return (1);
}