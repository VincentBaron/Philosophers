/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:22:04 by vbaron            #+#    #+#             */
/*   Updated: 2021/12/01 17:21:03 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

#define EAT 1
#define ENTER 2

typedef struct s_general
{
	struct s_philo *philo;
	pthread_mutex_t *forks;
	pthread_mutex_t write_mutex;
	pthread_mutex_t die_mutex;
	pthread_mutex_t eat_mutex;
	int can_write;
	int nb_philos;
	long long t_die;
	long long t_eat;
	long long t_sleep;
	int nb_eats;
} t_gen;

typedef struct s_philo
{
	int id;
	pthread_t thread;
	pthread_mutex_t lfork;
	pthread_mutex_t rfork;
	long long last_meal;
	int meals_left;
	t_gen *mother;
} t_philo;

// main.c


// fill_mother.c
int fill_mother(t_gen *mother, char **av, int ac);

// error.c
void error(t_gen *mother, int err);

// utils.c
long	ft_atoi(const char *nptr);
void safe_write(t_philo *philo, int type);

// check_args.c
void check_args(t_gen *mother, char **av);

// print_mother_attrs.c
void print_mother_attrs(t_gen *mother);

// sit_dowm_philos.c
int sit_down_philos(t_gen *mother);


// dinner_time.c
void *dinner_time(void *ptr_philo);


#endif