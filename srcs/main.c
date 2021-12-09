/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:40:58 by vbaron            #+#    #+#             */
/*   Updated: 2021/12/09 11:50:49 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	one_philo(t_gen *mother)
{
	long	start_t;

	safe_write(&mother->philo[0], FORK);
	start_t = get_time();
	while ((get_time() - start_t) < mother->t_die)
		usleep(100);
	safe_write(&mother->philo[0], DEAD);
}

void	init_threads(t_gen *mother)
{
	int	i;

	if (mother->nb_philos == 1)
		one_philo(mother);
	else
	{
		i = 0;
		while (i < mother->nb_philos)
		{
			pthread_create(&mother->philo[i].thread,
				NULL, &dinner_time, &mother->philo[i]);
			i++;
		}
		check_if_dead_or_done_eating(mother);
		i = 0;
		while (i < mother->nb_philos)
		{
			pthread_join(mother->philo[i].thread, NULL);
			i++;
		}
	}
}

void	clean_prgm(t_gen *mother)
{
	int	i;

	i = 0;
	while (i < mother->nb_philos)
	{
		pthread_mutex_destroy(&mother->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&mother->write_mutex);
	pthread_mutex_destroy(&mother->eat_mutex);
	free(mother->philo);
	free(mother->forks);
}

int	main(int ac, char **av)
{
	t_gen	mother;

	if (ac < 5 || ac > 6)
		error(&mother, 1);
	check_args(&mother, av, ac);
	fill_mother(&mother, av, ac);
	sit_down_philos(&mother);
	init_threads(&mother);
	clean_prgm(&mother);
	return (0);
}
