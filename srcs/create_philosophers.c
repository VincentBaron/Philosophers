/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philosophers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:16:09 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/24 12:46:59 by vbaron           ###   ########.fr       */
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
		mother->philo[i].lfork = NULL;
		mother->philo[i].rfork = NULL;
		mother->philo[i].time_to_eat = -1; 
	}
}

void fill_philos(t_general *mother, int id)
{
	int i;

	i = 0;
	while (i < mother->no_philos)
	{
		if (i == 0)
			pthread_mutex_init(mother->philo[i].lfork, NULL);
		else
			mother->philo[i].lfork = mother->philo[i - 1].rfork;
		if (i == mother->no_philos - 1)
			mother->philo[i].rfork = mother->philo[0].lfork;
		else
			pthread_mutex_init(mother->philo[i].rfork, NULL);
		
		
		
	}

	mother->philo[id].lfork = 
	
}

void create_philosophers(t_general *mother, char **av)
{
	int i;

	mother->no_philos = ft_atoi(av[1]);
	mother->time_to_die = ft_atoi(av[2]);
	mother->time_to_eat = ft_atoi(av[3]);
	mother->time_to_sleep = ft_atoi(av[4]);
	if (mother->no_args == 5)
		mother->no_eats = ft_atoi(av[5]);
	else
		mother->no_eats = -1;
	
	mother->philo = (t_philo *)malloc(sizeof(t_philo) * mother->no_philos);
	if (!mother->philo)
		err(mother, 3);
	init_philos(mother);
}