/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_mother.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:51:37 by vbaron            #+#    #+#             */
/*   Updated: 2021/12/06 19:24:05 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int fill_mother(t_gen *mother, char **av, int ac)
{
    int i;
    
    pthread_mutex_init(&mother->write_mutex, NULL);
    mother->dead_philo = -1;
    mother->dead_philo = -1;
    mother->can_write = 1;
    mother->start_time = get_time();
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
    i = -1;
    while (++i < mother->nb_philos)
        pthread_mutex_init(&mother->forks[i], NULL);
    if (!mother->philo || mother->forks)
        return (0);
    return (1);
}