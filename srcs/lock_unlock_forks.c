/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_unlock_forks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:20:49 by vbaron            #+#    #+#             */
/*   Updated: 2021/12/03 17:23:09 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void lock_forks(t_philo *philo)
{
    if (philo->id % 2 == 0)
    {
        pthread_mutex_lock(philo->lfork);
        safe_write2(philo, FORK);
        pthread_mutex_lock(philo->rfork);
        safe_write2(philo, FORK);
    }
    else
    {
        pthread_mutex_lock(philo->rfork);
        safe_write2(philo, FORK);
        pthread_mutex_lock(philo->lfork);
        safe_write2(philo, FORK);
    }
}

void unlock_forks(t_philo *philo)
{
    if (philo->id % 2 == 0)
    {
        pthread_mutex_unlock(philo->lfork);
        pthread_mutex_unlock(philo->rfork);
    }
    else
    {
        pthread_mutex_unlock(philo->rfork);
        pthread_mutex_unlock(philo->lfork);
    }
}