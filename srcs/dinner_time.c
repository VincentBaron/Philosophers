/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:49:40 by vbaron            #+#    #+#             */
/*   Updated: 2021/12/07 15:12:31 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void eat(t_philo *philo)
{
    safe_write(philo, EAT);
    my_sleep(philo->mother->t_eat);
    pthread_mutex_lock(&philo->mother->eat_mutex);
    philo->last_meal = get_time();
    philo->nb_eats--;
    pthread_mutex_unlock(&philo->mother->eat_mutex);
}

void sleeping(t_philo *philo)
{
    safe_write(philo, SLEEP);
    my_sleep(philo->mother->t_sleep);
}

void *dinner_time(void *ptr_philo)
{
    t_philo *philo;
    int     keep_on;
    
    philo = (t_philo *)ptr_philo;
	if (philo->id % 2 == 0)
		usleep(100);
    pthread_mutex_lock(&philo->mother->write_mutex);
    keep_on = philo->mother->can_write;
    pthread_mutex_unlock(&philo->mother->write_mutex);
    if (!keep_on)
        return (0);
    lock_forks(philo);
    eat(philo);
    unlock_forks(philo);
    sleeping(philo);
    safe_write(philo, THINK);
     pthread_mutex_lock(&philo->mother->write_mutex);
    keep_on = philo->mother->can_write;
    pthread_mutex_unlock(&philo->mother->write_mutex);
    if (keep_on)
        dinner_time(philo);
    return (NULL);
}