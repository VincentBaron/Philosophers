/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:41:42 by vbaron            #+#    #+#             */
/*   Updated: 2021/12/02 17:05:08 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int check_if_dead_or_done_eating(t_gen *mother)
{
    int i;
    t_philo *end_philo;
    t_philo *dead_philo;

    
    end_philo = NULL;
    dead_philo = NULL;
    while (1)
    {
        i = 0;
        while (i < mother->nb_philos)
        {
            if (mother->philo[i].nb_eats == 0)
            {
                end_philo = &mother->philo[i];
                break ;
            }
            // if (get_time() - mother->philo[i].last_meal > mother->t_die)
            // {
            //     dead_philo = &mother->philo[i];
            //     break ;
            // }
            i++;
        }
        if (end_philo || dead_philo)
        {
            mother->can_write = 0;
            if (dead_philo)
                safe_write(dead_philo, DEAD);
            break ;
        }
    }
    return (1);
}