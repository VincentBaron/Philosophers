/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philos_attrs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:24:45 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/24 16:59:50 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void print_philos(t_general *mother)
{
	int i;

	i = 0;
	while (i < mother->no_philos)
	{
		printf("--------------------\n\nphilo %d:\n\n", mother->philo[i].id);
		printf("philo addr: %d\n", (int)&mother->philo[i]);
		printf("philo thread: %d\n", (int)mother->philo[i].thread);
		printf("philo lfork addr: %d\n", (int)&mother->philo[i].lfork);
		printf("philo rfork addr: %d\n", (int)&mother->philo[i].rfork);
		printf("philo lfork locked: %d\n", (int)mother->philo[i].lfork_locked);
		printf("philo rfork locked: %d\n", (int)mother->philo[i].rfork_locked);
		printf("philo speak locked: %d\n", (int)mother->philo[i].speak_locked);
		i++;
	}
}