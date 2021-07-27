/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:19:55 by ggilbert          #+#    #+#             */
/*   Updated: 2021/07/27 14:27:56 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	init_stack(t_stack *x, int max_size, char stack_name)
{
	x->max_s = max_size - 1;
	x->is_sort = false;
	x->arr = malloc(sizeof(int) * x->max_s);
	if (x->arr == NULL)
		return (false);
	ft_memset(x->arr, 0, x->max_s * sizeof(int));
	x->biggest = 0;
	x->smallest = 0;
	x->current_s = 0;
	x->top_pos = x->max_s;
	x->stack_name = stack_name;
	return (true);
}

t_bool	is_short(t_stack *x)
{
	size_t	i;

	if (x->is_sort)
		return (true);
	i = 0;
	while (i <= x->max_s - 1 && x->max_s != 1)
	{
		if (x->arr[i] < x->arr[i + 1])
			i++;
		else
		{
			x->is_sort = false;
			return (false);
		}
	}
	x->is_sort = true;
	return (true);
}

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
	while (i <= x->max_s - 1)
	{
		if (x->smallest > x->arr[i])
			x->smallest = x->arr[i];
		i++;
	}
}
