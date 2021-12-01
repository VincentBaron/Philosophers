/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:41:42 by vbaron            #+#    #+#             */
/*   Updated: 2021/12/01 22:26:43 by vbaron           ###   ########.fr       */
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
                end_philo = &mother->philo[i];
            i++;
        }
        if (end_philo != NULL)
        {
            safe_write(end_philo, FINISH_EAT);
            break ;
        }
    }
    return (1);
}