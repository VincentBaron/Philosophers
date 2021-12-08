/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_mother.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:51:37 by vbaron            #+#    #+#             */
/*   Updated: 2021/12/08 15:24:50 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	init_vars(t_gen *mother, char **av)
{
	pthread_mutex_init(&mother->write_mutex, NULL);
	pthread_mutex_init(&mother->eat_mutex, NULL);
	mother->can_write = 1;
	mother->start_time = get_time();
	mother->nb_philos = ft_atoi(av[1]);
	mother->t_die = ft_atoi(av[2]);
	mother->t_eat = ft_atoi(av[3]);
	mother->t_sleep = ft_atoi(av[4]);
}

int	fill_mother(t_gen *mother, char **av, int ac)
{
	int	i;

	init_vars(mother, av);
	if (ac == 6)
	{
		mother->nb_eats = ft_atoi(av[5]);
	}
	else
		mother->nb_eats = -1;
	mother->philo = NULL;
	mother->forks = NULL;
	mother->philo = (t_philo *)malloc(sizeof(t_philo) * mother->nb_philos);
	mother->forks = (pthread_mutex_t *)
		malloc(sizeof(pthread_mutex_t) * mother->nb_philos);
	i = 0;
	while (++i < mother->nb_philos)
	{
		pthread_mutex_init(&mother->forks[i], NULL);
		i++;
	}
	if (!mother->philo || mother->forks)
		return (0);
	return (1);
}
