/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_unlock_forks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:20:49 by vbaron            #+#    #+#             */
/*   Updated: 2021/12/07 15:17:22 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void lock_forks(t_philo *philo)
{
    if (philo->id % 2 == 1)
    {
        pthread_mutex_lock(philo->rfork);
        pthread_mutex_lock(philo->lfork);
    }
    else
    {
        pthread_mutex_lock(philo->lfork);
        pthread_mutex_lock(philo->rfork);
    }
    safe_write(philo, FORK);
    safe_write(philo, FORK);
}

void unlock_forks(t_philo *philo)
{
    pthread_mutex_unlock(philo->lfork);
    pthread_mutex_unlock(philo->rfork);
}