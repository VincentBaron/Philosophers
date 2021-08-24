/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philosophers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:16:09 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/24 17:08:36 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void init_philos(t_general *mother)
{
	int i;

	i = 0;
	while (i < mother->no_philos)
	{
		mother->philo[i].id = -1;
		mother->philo[i].time_to_eat = -1;
		i++;
	}
}

void fill_philos(t_general *mother)
{
	int i;

	i = 0;
	while (i < mother->no_philos)
	{
		mother->philo[i].time_to_eat = mother->time_to_eat;
		mother->philo[i].no_eats = mother->no_eats;
		mother->philo[i].id = i;
		if (i == 0)
			pthread_mutex_init(&(mother->philo[i].lfork), NULL);
		else
			&(mother->philo[i].lfork) = &(mother->philo[i - 1].rfork);
		if (i == mother->no_philos - 1)
			&(mother->philo[i].rfork) = &(mother->philo[0].lfork);
		else
			pthread_mutex_init(&(mother->philo[i].rfork), NULL);
		unlock_fork(&(mother->philo[i]));
		lock_speak(&(mother->philo[i]));
		i++;	
	}
	print_philos(mother);
}

void create_philosophers(t_general *mother, char **av)
{
	mother->no_philos = ft_atoi(av[1]);
	mother->time_to_die = ft_atoi(av[2]);
	mother->time_to_eat = ft_atoi(av[3]);
	mother->time_to_sleep = ft_atoi(av[4]);
	if (mother->no_args == 6)
		mother->no_eats = ft_atoi(av[5]);
	else
		mother->no_eats = -1;
	
	mother->philo = (t_philo *)malloc(sizeof(t_philo) * mother->no_philos);
	if (!mother->philo)
		error(mother, 3);
	init_philos(mother);
	print_philos(mother);
	fill_philos(mother);
}