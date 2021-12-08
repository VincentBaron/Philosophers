/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:40:58 by vbaron            #+#    #+#             */
/*   Updated: 2021/12/08 15:06:10 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int ac, char **av)
{
	t_gen	mother;
	int		i;

	if (ac < 5 || ac > 6)
		error(&mother, 1);
	check_args(&mother, av, ac);
	fill_mother(&mother, av, ac);
	sit_down_philos(&mother);
	i = 0;
	while (i < mother.nb_philos)
	{
		pthread_create(&mother.philo[i].thread,
			NULL, &dinner_time, &mother.philo[i]);
		if (mother.nb_philos % 2 == 1)
			usleep(100);
		i++;
	}
	check_if_dead_or_done_eating(&mother);
	i = 0;
	while (i < mother.nb_philos)
	{
		pthread_join(mother.philo[i].thread, NULL);
		i++;
	}
	return (0);
}
