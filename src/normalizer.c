/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:31:48 by ggilbert          #+#    #+#             */
/*   Updated: 2021/08/01 15:15:15 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	copy_stack(t_stack *base, t_stack *copy, char name)
{
	size_t	i;

	i = 0;
	if (!init_stack(copy, base->max_s + 1, name))
		return (false);
	while (i < base->max_s)
	{
		copy->arr[i] = base->arr[i];
		copy->current_s++;
		i++;
	}
	copy->top_pos = base->top_pos;
	copy->smallest_pos = base->smallest_pos;
	copy->smallest = base->smallest;
	return (true);
}

void	bubble_sort(t_stack *copy)
{
	int		tmp;
	size_t	i;

	i = copy->top_pos;
	while (i < copy->max_s)
	{
		find_smallest_pos(copy);
		tmp = copy->arr[copy->top_pos];
		copy->arr[copy->top_pos] = copy->arr[copy->smallest_pos];
		copy->arr[copy->smallest_pos] = tmp;
		copy->top_pos++;
		i++;
	}
}

t_bool	stack_normalizer(t_stack *a)
{
	t_stack	copy;
	int		i;
	int		j;

	if (!copy_stack(a, &copy, 't'))
		return (false);
	bubble_sort(&copy);
	i = 0;
	while (i < (int)a->max_s)
	{
		j = 0;
		while (j < (int)copy.max_s)
		{
			if (a->arr[i] == copy.arr[j])
			{
				a->arr[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	if (copy.arr)
		free(copy.arr);
	return (true);
}
