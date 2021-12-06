/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:49:40 by vbaron            #+#    #+#             */
/*   Updated: 2021/12/06 15:27:42 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void eat(t_philo *philo)
{
    safe_write(philo, EAT);
    my_sleep(philo->mother->t_eat);
    pthread_mutex_lock(&philo->death_checker);
    philo->last_meal = get_time();
    philo->nb_eats--;
    pthread_mutex_unlock(&philo->death_checker);

}

void sleeping(t_philo *philo)
{
    safe_write(philo, SLEEP);
    my_sleep(philo->mother->t_sleep);
}

void *dinner_time(void *ptr_philo)
{
    t_philo *philo;
    int keep_eating;

    keep_eating = 1;
    philo = (t_philo *)ptr_philo;
    lock_forks(philo);
    eat(philo);
    unlock_forks(philo);
    sleeping(philo);
    safe_write(philo, THINK);
    pthread_mutex_lock(&philo->death_checker);
    if (philo->mother->end_philo || philo->nb_eats == 0)
        keep_eating = 0;
    pthread_mutex_unlock(&philo->death_checker);
    if (keep_eating)
        dinner_time(philo);
    return (NULL);
}