/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:45:39 by vbaron            #+#    #+#             */
/*   Updated: 2021/12/07 14:24:16 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void print_philos(t_gen *mother)
{
    int i;

    i = 0;
    while (i < mother->nb_philos)
    {
        printf("philo id: %d\n", mother->philo[i].id);
        printf("philo lfork %p\n", mother->philo[i].lfork);
        printf("philo rfork %p\n", mother->philo[i].rfork);
        printf("nb eats %d\n", mother->philo[i].nb_eats);
        printf("id modulo 2: %d\n", mother->philo[i].id % 2);
        i++;
    }
}