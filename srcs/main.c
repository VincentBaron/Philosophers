/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:40:58 by vbaron            #+#    #+#             */
/*   Updated: 2021/08/24 16:48:57 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int main(int ac, char **av)
{
	(void)av;
	t_general mother;
	
	if (ac < 5)
		error(&mother, 1);
		mother.no_args = ac;
	check_args(&mother, av);
	mother.end = -1;
	create_philosophers(&mother, av);
	// start_dinner(&mother);
	return (0);
}