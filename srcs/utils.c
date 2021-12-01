/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:05:38 by vbaron            #+#    #+#             */
/*   Updated: 2021/12/01 17:59:06 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long	ft_atoi(const char *nptr)
{
	int				i;
	long		nbr;
	int				sign;

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

void safe_write(t_philo *philo, int type)
{
	if (type == EAT)
	{
		pthread_mutex_lock(&philo->mother->write_mutex);
		printf("Philo %d is eating\n", philo->id);
		pthread_mutex_unlock(&philo->mother->write_mutex);
	}
	if (type == ENTER)
	{
		pthread_mutex_lock(&philo->mother->write_mutex);
		printf("Philo %d is in thread\n", philo->id);
		pthread_mutex_unlock(&philo->mother->write_mutex);
	}
}