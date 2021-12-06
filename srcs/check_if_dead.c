/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:41:42 by vbaron            #+#    #+#             */
/*   Updated: 2021/12/06 19:02:08 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int check_if_dead_or_done_eating(t_gen *mother)
{
    int i;
    
    while (1)
    {
        pthread_mutex_lock(&mother->finish_mutex);
        if (mother->done_eating >= mother->nb_philos)
        {
            pthread_mutex_lock(&mother->write_mutex);
            mother->can_write = 0;
            pthread_mutex_unlock(&mother->write_mutex);
            mother->finish = 1;
        }
        pthread_mutex_unlock(&mother->finish_mutex);
        usleep(10);
        pthread_mutex_lock(&mother->finish_mutex);
        i = 0;
        while (i < mother->nb_eats)
        {
            if (get_time() - mother->philo[i].last_meal >= mother->t_die)
            {
                safe_write(&mother->philo[i], DEAD);
                pthread_mutex_lock(&mother->write_mutex);
                mother->can_write = 0;
                pthread_mutex_unlock(&mother->write_mutex);
                mother->finish = 1;
                break ;
            }
            i++;
        }
        pthread_mutex_unlock(&mother->finish_mutex);
        if (i <= mother->nb_philos)
            return (1);
        usleep(10);
    }
    return (1);
}