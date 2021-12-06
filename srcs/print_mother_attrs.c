/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mother_attrs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:24:32 by vbaron            #+#    #+#             */
/*   Updated: 2021/12/06 18:47:46 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philosophers.h"

void print_mother_attrs(t_gen *mother)
{
    printf("can_write: %d\n", mother->can_write);
    printf("nb_philos: %d\n", mother->nb_philos);
    printf("t_die: %ld\n", mother->t_die);
    printf("t_eat: %ld\n", mother->t_eat);
    printf("t_sleep: %ld\n", mother->t_sleep);
    printf("nb_eats: %d\n", mother->nb_eats);
}