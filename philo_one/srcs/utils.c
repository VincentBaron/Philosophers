/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:05:38 by vbaron            #+#    #+#             */
/*   Updated: 2021/12/08 17:48:44 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long ft_atoi(const char *nptr)
{
	int i;
	long nbr;
	int sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (nptr[i] && (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13)))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		nbr = nbr * 10 + (nptr[i] - 48);
		i++;
	}
	if (nbr < 0 && sign > 0)
		return (-1);
	else if (nbr < 0 && sign < 0 && nbr * sign != -2147483648)
		return (0);
	return ((nbr * sign));
}

void my_sleep(long long time, t_gen *mother)
{
	int i;
	int stat;
	long long start_t;

	start_t = get_time();
	i = 0;
	while ((get_time() - start_t) < time)
	{
		usleep(100);
		pthread_mutex_lock(&mother->eat_mutex);
		stat = mother->can_write;
		pthread_mutex_unlock(&mother->eat_mutex);
		if (!stat)
			break;
		i++;
	}
}

long get_time(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void safe_write(t_philo *philo, int type)
{
	long time_stamp;

	pthread_mutex_lock(&philo->mother->write_mutex);
	time_stamp = get_time() - philo->mother->start_time;
	if (type == EAT && philo->mother->can_write)
		printf("%ld %d is eating\n", time_stamp, philo->id);
	if (type == SLEEP && philo->mother->can_write)
		printf("%ld %d is sleeping\n", time_stamp, philo->id);
	if (type == THINK && philo->mother->can_write)
		printf("%ld %d is thinking\n", time_stamp, philo->id);
	if (type == FORK && philo->mother->can_write)
		printf("%ld %d has taken a fork\n", time_stamp, philo->id);
	if (type == DEAD)
		printf("%ld %d died\n", time_stamp, philo->id);
	if (type == FINISH)
		printf("All Philos finished eating %d times\n", philo->mother->nb_eats);
	pthread_mutex_unlock(&philo->mother->write_mutex);
}
