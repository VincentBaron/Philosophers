/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:12:22 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/24 15:28:09 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void eat(t_philo *philo)
{
	lock_fork(philo);
	printf("philo[%d] is eating", philo->id);
	usleep(philo->time_to_eat);
}

void *request_eating(void *void_philo)
{
	t_philo *philo;

	philo = (t_philo *)void_philo;
	if (philo->lfork_locked == 0 && philo->rfork_locked == 0)
		eat(philo);
	return (0);
}

void start_dinner(t_general *mother)
{
	int i;

	i = 0;
	while(i < mother->no_philos)
	{
		pthread_create(&(mother->philo[i].thread), NULL, request_eating, &(mother->philo[i]));
		i++;
	}
}