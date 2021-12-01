/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:49:40 by vbaron            #+#    #+#             */
/*   Updated: 2021/12/01 17:23:08 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void *dinner_time(void *ptr_philo)
{
    t_philo *philo;
    
    philo = (t_philo *)ptr_philo;
    pthread_mutex_lock(&philo->mother->eat_mutex);
    safe_write(philo, EAT);
    usleep(philo->mother->t_eat);
    pthread_mutex_unlock(&philo->mother->eat_mutex);
    philo->meals_left--;
    while (philo->meals_left != 0)
        dinner_time(philo);
    return (NULL);
}