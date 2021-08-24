/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_locking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:58:51 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/24 15:13:47 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void lock_speak(t_philo *philo)
{
	pthread_mutex_lock(philo->speak);
	philo->speak_locked = 1;
}

void unlock_speak(t_philo *philo)
{
	pthread_mutex_unlock(philo->speak);
	philo->speak_locked = 0;
}

void unlock_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->lfork);
	philo->lfork_locked = 0;
	pthread_mutex_unlock(philo->rfork);
	philo->rfork_locked = 0;
}

void lock_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->lfork);
	philo->lfork_locked = 1;
	pthread_mutex_lock(philo->rfork);
	philo->rfork_locked = 1;
}