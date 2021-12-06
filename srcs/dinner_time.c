/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:49:40 by vbaron            #+#    #+#             */
/*   Updated: 2021/12/06 19:03:30 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void eat(t_philo *philo)
{
    lock_forks(philo);
    safe_write(philo, EAT);
    my_sleep(philo->mother->t_eat);
    unlock_forks(philo);
    pthread_mutex_lock(&philo->mother->finish_mutex);
    philo->last_meal = get_time();
    philo->nb_eats--;
    if (philo->nb_eats > philo->mother->nb_eats)
        philo->mother->done_eating++;
    pthread_mutex_unlock(&philo->mother->finish_mutex);

}

void sleeping(t_philo *philo)
{
    safe_write(philo, SLEEP);
    my_sleep(philo->mother->t_sleep);
}

void *dinner_time(void *ptr_philo)
{
    t_philo *philo;
    int finish;

    philo = (t_philo *)ptr_philo;
    if(philo->id % 2 == 0)
        usleep(100);
    pthread_mutex_lock(&philo->mother->finish_mutex);
    finish = philo->mother->finish;
    pthread_mutex_unlock(&philo->mother->finish_mutex);
    eat(philo);
    sleeping(philo);
    safe_write(philo, THINK);
    pthread_mutex_lock(&philo->mother->finish_mutex);
    finish = philo->mother->finish;
    pthread_mutex_unlock(&philo->mother->finish_mutex);
    if (!finish)
        dinner_time(philo);
    return (NULL);
}