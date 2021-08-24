/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:22:04 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/24 15:27:14 by vbaron           ###   ########.fr       */
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
	pthread_t thread;
	pthread_mutex_t *lfork;
	pthread_mutex_t *rfork;
	pthread_mutex_t *speak;
	int speak_locked;
	int lfork_locked;
	int rfork_locked;
	int time_to_eat;
	int no_eats;
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


// creeate_philosophers.c

void create_philosophers(t_general *mother, char **av);
void fill_philos(t_general *mother);
void init_philos(t_general *mother);

// dinner.c

void start_dinner(t_general *mother);
void *request_eating(void *void_philo);
void eat(t_philo *philo);

// err.c

void error(t_general *mother, int err);

// utils.c

long	ft_atoi(const char *nptr);

// mutex_locking.c

void unlock_fork(t_philo *philo);
void lock_fork(t_philo *philo);
void unlock_speak(t_philo *philo);
void lock_speak(t_philo *philo);


// check_args.c

void check_args(t_general *mother, char **av);


#endif