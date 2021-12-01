/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:48:38 by vbaron            #+#    #+#             */
/*   Updated: 2021/12/01 15:10:59 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void error(t_gen *mother, int err)
{
	(void)mother;
	if (err == 1)
		printf("Error: Wrong number of arguments.\n");
	if (err == 2)
		printf("Error: Arguments are invalid.\n");
	if (err == 3)
		printf("Error: Bad malloc.\n");
	exit(1);
}