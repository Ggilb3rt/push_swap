/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 09:08:49 by ggilbert          #+#    #+#             */
/*   Updated: 2021/07/29 11:25:34 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Les find smallest et biggest ne prennent pas en compte la current_s
//	ni le top de la stack cf find_smalloest_pos pour solution
void	find_biggest(t_stack *x)
{
	size_t	i;

	i = 0;
	while (i <= x->max_s - 1)
	{
		if (x->biggest < x->arr[i])
			x->biggest = x->arr[i];
		i++;
	}
}

void	find_smallest(t_stack *x)
{
	size_t	i;

	i = 0;
	x->smallest = x->arr[x->top_pos];
	while (i <= x->max_s - 1)
	{
		if (x->smallest > x->arr[i])
			x->smallest = x->arr[i];
		i++;
	}
}

void	find_smallest_pos(t_stack *x)
{
	size_t	i;

	x->smallest_pos = x->top_pos;
	i = x->top_pos;
	while (i <= x->max_s - 1)
	{
		if (x->arr[x->smallest_pos] > x->arr[i])
			x->smallest_pos = i;
		i++;
	}
}
