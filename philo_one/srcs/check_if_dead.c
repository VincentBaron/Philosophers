/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:41:42 by vbaron            #+#    #+#             */
/*   Updated: 2021/12/08 16:41:10 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	check_nbr_eats(t_gen *mother)
{
	pthread_mutex_lock(&mother->eat_mutex);
	if (mother->done_eating >= mother->nb_philos)
	{
		pthread_mutex_lock(&mother->write_mutex);
		mother->can_write = 0;
		pthread_mutex_unlock(&mother->write_mutex);
		safe_write(&mother->philo[0], FINISH);
		pthread_mutex_unlock(&mother->eat_mutex);
		return (1);
	}
	pthread_mutex_unlock(&mother->eat_mutex);
	return (0);
}

int	check_death(t_gen *mother, int i)
{
	t_philo	*end_philo;
	long	eat_time;

	end_philo = NULL;
	pthread_mutex_lock(&mother->eat_mutex);
	eat_time = mother->philo[i].last_meal;
	pthread_mutex_unlock(&mother->eat_mutex);
	if (get_time() - eat_time > mother->t_die)
	{
		pthread_mutex_lock(&mother->write_mutex);
		mother->can_write = 0;
		pthread_mutex_unlock(&mother->write_mutex);
		end_philo = &mother->philo[i];
		safe_write(end_philo, DEAD);
		return (1);
	}
	return (0);
}

int	check_if_dead_or_done_eating(t_gen *mother)
{
	int	i;

	while (1)
	{
		if (check_nbr_eats(mother))
			return (1);
		i = 0;
		while (i < mother->nb_philos)
		{
			if (check_death(mother, i))
				return (1);
			i++;
		}
		usleep(10);
	}
	return (1);
}
