/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:07:59 by vbaron            #+#    #+#             */
/*   Updated: 2021/12/01 15:09:58 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void check_args(t_gen *mother, char **av)
{
	int i;
	int f;

	i = 1;
	while (av[i])
	{
		f = 0;
		while (av[i][f])
		{
			if (av[i][f] < '0' || av[i][f] > '9')
				error(mother, 2);
			f++;
		}
		i++;
	}
}