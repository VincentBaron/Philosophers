/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:41:42 by vbaron            #+#    #+#             */
/*   Updated: 2021/12/03 17:21:51 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int check_if_dead_or_done_eating(t_gen *mother)
{
    int i;
    t_philo *end_philo;

    end_philo = NULL;
    while (1)
    {
        i = 0;
        while (i < mother->nb_philos)
        {
            if (mother->philo[i].nb_eats == 0)
            {
                mother->can_write = 0;
                end_philo = &mother->philo[i];
                break;
            }
            if (get_time() - mother->philo[i].last_meal > mother->t_die)
            {
                mother->can_write = 0;
                end_philo = &mother->philo[i];
                safe_write2(end_philo, DEAD);
                break;
            }
            i++;
        }
        if (end_philo)
            break ;
    }
    return (1);
}