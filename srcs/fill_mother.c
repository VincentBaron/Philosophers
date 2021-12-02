/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_mother.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:51:37 by vbaron            #+#    #+#             */
/*   Updated: 2021/12/02 17:02:33 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int fill_mother(t_gen *mother, char **av, int ac)
{
    pthread_mutex_init(&mother->write_mutex, NULL);
    pthread_mutex_init(&mother->die_mutex, NULL);
    pthread_mutex_init(&mother->eat_mutex, NULL);
    mother->can_write = 1;
    mother->end = 0;
    mother->nb_philos = ft_atoi(av[1]);
	mother->t_die = ft_atoi(av[2]);
	mother->t_eat = ft_atoi(av[3]);
	mother->t_sleep = ft_atoi(av[4]);
    if (ac == 6)
        mother->nb_eats = ft_atoi(av[5]);
    mother->philo = NULL;
    mother->forks = NULL;
    mother->philo = (t_philo *)malloc(sizeof(t_philo) * mother->nb_philos);
    mother->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * mother->nb_philos);
    if (!mother->philo || mother->forks)
        return (0);
    return (1);
}