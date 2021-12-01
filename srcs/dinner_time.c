/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:49:40 by vbaron            #+#    #+#             */
/*   Updated: 2021/12/01 22:30:51 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void eat(t_philo *philo)
{
    safe_write(philo, EAT);
    my_sleep(philo->mother->t_eat);
    philo->nb_eats--;
}

void sleeping(t_philo *philo)
{
    safe_write(philo, SLEEP);
    my_sleep(philo->mother->t_sleep);
}

void *dinner_time(void *ptr_philo)
{
    t_philo *philo;
    
    philo = (t_philo *)ptr_philo;
    if (philo->id % 2 == 0)
    {
        pthread_mutex_lock(&philo->lfork);
        pthread_mutex_lock(&philo->rfork);
    }
    else
    {
        pthread_mutex_lock(&philo->rfork);
        pthread_mutex_lock(&philo->lfork);
    }
    eat(philo);
    sleeping(philo);
    safe_write(philo, THINK);
    return (NULL);
}