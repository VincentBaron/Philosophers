/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:49:40 by vbaron            #+#    #+#             */
/*   Updated: 2021/12/06 19:15:00 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void eat(t_philo *philo)
{
    safe_write(philo, EAT);
    my_sleep(philo->mother->t_eat);
    philo->last_meal = get_time();
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
    lock_forks(philo);
    eat(philo);
    unlock_forks(philo);
    sleeping(philo);
    safe_write(philo, THINK);
    while (philo->nb_eats != 0)
        dinner_time(philo);
    return (NULL);
}