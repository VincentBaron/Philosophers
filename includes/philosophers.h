/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:22:04 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/24 12:22:22 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int id;
	pthread_mutex_t *lfork;
	pthread_mutex_t *rfork;
	pthread_mutex_t speak;
	int time_to_eat;
} t_philo;

typedef struct s_general
{
	t_philo *philo;
	int no_philos;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int no_eats;
	int no_args;
} t_general;

// main.c


// err.c

void error(t_general *mother, int err);

// utils.c

long	ft_atoi(const char *nptr);

// check_args.c

void check_args(t_general *mother, char **av);


#endif