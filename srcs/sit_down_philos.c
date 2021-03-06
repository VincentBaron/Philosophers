/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sit_down_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:36:59 by vbaron            #+#    #+#             */
/*   Updated: 2021/12/08 16:53:31 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	sit_down_philos(t_gen *mother)
{
	int	i;

	i = 0;
	while (i < mother->nb_philos)
	{
		mother->philo[i].lfork = NULL;
		mother->philo[i].rfork = NULL;
		mother->philo[i].id = i + 1;
		if (i == 0)
			mother->philo[i].lfork = &mother->forks[mother->nb_philos - 1];
		else
			mother->philo[i].lfork = &mother->forks[i - 1];
		mother->philo[i].rfork = &mother->forks[i];
		mother->philo[i].mother = mother;
		mother->philo[i].nb_eats = mother->nb_eats;
		mother->philo[i].last_meal = get_time();
		i++;
	}
	return (1);
}
