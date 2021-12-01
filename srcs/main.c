/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:40:58 by vbaron            #+#    #+#             */
/*   Updated: 2021/12/01 15:30:02 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int main(int ac, char **av)
{
	(void)av;
	t_gen mother;
	
	if (ac < 5 || ac > 6)
		error(&mother, 1);
	check_args(&mother, av);
	fill_mother(&mother, av, ac);
	print_mother_attrs(&mother);
	// sit_down_philos(&mother);
	return (0);
}