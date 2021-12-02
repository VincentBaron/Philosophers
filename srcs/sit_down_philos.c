/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sit_down_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:36:59 by vbaron            #+#    #+#             */
/*   Updated: 2021/12/02 12:13:03 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philosophers.h"

int sit_down_philos(t_gen *mother)
{
    int i;

    i = 0;
    while (i < mother->nb_philos)
    {
        printf("forks[%d]: %p\n", i, &mother->forks[i]);
        i++;
    }
    i = 0;
    while (i < mother->nb_philos)
    {
        mother->philo[i].id = i + 1;
        if (i == 0)
            mother->philo[i].lfork = &mother->forks[mother->nb_philos - 1];
        else
            mother->philo[i].lfork = &mother->forks[i - 1];
        mother->philo[i].rfork = &mother->forks[i];
        mother->philo[i].meals_left = mother->nb_eats;
        mother->philo[i].mother = mother;
        mother->philo[i].nb_eats = mother->nb_eats;
        printf("philo id: %d\n", mother->philo[i].id);
        printf("philo lfork %p\n", mother->philo[i].lfork);
        printf("philo rfork %p\n", mother->philo[i].rfork);
        i++;
    }
    return (1);

}