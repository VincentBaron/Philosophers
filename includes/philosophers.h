/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:22:04 by vbaron            #+#    #+#             */
/*   Updated: 2021/12/06 18:46:41 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

enum {EAT, SLEEP, THINK, DEAD, FORK};

typedef struct s_general
{
	struct s_philo *philo;
	pthread_mutex_t *forks;
	pthread_mutex_t write_mutex;
	pthread_mutex_t finish_mutex;
	int nb_philos;
	long t_die;
	long t_eat;
	long t_sleep;
	int nb_eats;
	int done_eating;
	int can_write;
	struct s_philo *end_philo;
	long start_time;
	int finish;
} t_gen;

typedef struct s_philo
{
	int id;
	pthread_t thread;
	pthread_mutex_t *lfork;
	pthread_mutex_t *rfork;
	long long last_meal;
	int nb_eats;
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
void safe_write2(t_philo *philo, int type);
void my_sleep(long long time);
long get_time();

// check_args.c
void check_args(t_gen *mother, char **av);

// print_mother_attrs.c
void print_mother_attrs(t_gen *mother);

// sit_dowm_philos.c
int sit_down_philos(t_gen *mother);


// dinner_time.c
void *dinner_time(void *ptr_philo);

// check_if_dead.c
int check_if_dead_or_done_eating(t_gen *mother);

// lock_unlock_forks.c
void lock_forks(t_philo *philo);
void unlock_forks(t_philo *philo);

// print_philos.c
void print_philos(t_gen *mother);


#endif