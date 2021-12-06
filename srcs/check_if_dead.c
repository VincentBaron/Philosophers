/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:41:42 by vbaron            #+#    #+#             */
/*   Updated: 2021/12/06 15:37:17 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int check_if_dead_or_done_eating(t_gen *mother)
{
    int i;

    mother->end_philo = NULL;
    while (1)
    {
        i = 0;
        while (i < mother->nb_philos)
        {
            pthread_mutex_lock(&mother->philo[i].death_checker);
            if (mother->philo[i].nb_eats == 0)
            {
                mother->can_write = 0;
                mother->end_philo = &mother->philo[i];
            }
            if (get_time() - mother->philo[i].last_meal > mother->t_die)
            {
                mother->can_write = 0;
                mother->end_philo = &mother->philo[i];
                safe_write2(mother->end_philo, DEAD);
            }
            pthread_mutex_unlock(&mother->philo[i].death_checker);
            if (mother->end_philo)
                return (1);
            i++;
        }
    }
    return (1);
}