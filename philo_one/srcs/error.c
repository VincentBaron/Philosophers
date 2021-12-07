/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:48:38 by vbaron            #+#    #+#             */
/*   Updated: 2021/12/07 18:09:32 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int ft_strlen(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

void error(t_gen *mother, int err)
{
	(void)mother;
	if (err == 1)
		ft_putstr_fd("Error: Wrong number of arguments.\n", STDERR_FILENO);
	if (err == 2)
		ft_putstr_fd("Error: Arguments are invalid.\n", STDERR_FILENO);
	if (err == 3)
		ft_putstr_fd("Error: Bad malloc.\n", STDERR_FILENO);
	exit(1);
}