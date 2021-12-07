/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:07:59 by vbaron            #+#    #+#             */
/*   Updated: 2021/12/07 18:18:22 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void check_args(t_gen *mother, char **av, int ac)
{
	int i;
	int f;

	i = 1;
	if (ac == 6 && (ft_strlen(av[5]) > 10 || ft_atoi(av[5]) > 2147483647 || ft_atoi(av[5]) < -2147483648))
		error(mother, 2);
	while (av[i])
	{
		f = 0;
		if (ft_strlen(av[i]) > 10 || ft_atoi(av[i]) > 2147483647 || ft_atoi(av[i]) < -2147483648)
			error(mother, 2);
		while (av[i][f])
		{
			if (av[i][f] < '0' || av[i][f] > '9')
				error(mother, 2);
			f++;
		}
		i++;
	}

}