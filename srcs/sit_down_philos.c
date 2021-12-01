/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sit_down_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:36:59 by vbaron            #+#    #+#             */
/*   Updated: 2021/12/01 22:10:48 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philosophers.h"

int sit_down_philos(t_gen *mother)
{
    int i;

    i = 0;
    while (i < mother->nb_philos)
    {
        mother->philo[i].id = i + 1;
        if (i == 0)
            mother->philo[i].lfork = mother->forks[mother->nb_philos - 1];
        else
            mother->philo[i].lfork = mother->forks[i - 1];
        if (i == mother->nb_philos - 1)
            mother->philo[i].rfork = mother->forks[0];
        else
            mother->philo[i].lfork = mother->forks[i + 1];
        mother->philo[i].meals_left = mother->nb_eats;
        mother->philo[i].mother = mother;
        mother->philo[i].nb_eats = mother->nb_eats;
        i++;
    }
    return (1);

}