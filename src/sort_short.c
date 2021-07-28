/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 09:48:12 by ggilbert          #+#    #+#             */
/*   Updated: 2021/07/28 14:36:56 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	very_short_big_first(t_stack *a)
{
	if (a->arr[1] > a->arr[2])
	{
		swap(a, true);
		reverse_rotate(a, true);
	}
	else
		rotate(a, true);
}

void	very_short_small_first(t_stack *a)
{
	if (a->arr[1] > a->arr[2])
	{
		reverse_rotate(a, true);
		swap(a, true);
	}
}

void	very_short_sort(t_stack *a)
{
	if (a->current_s > 3 || a->is_sort)
		return ;
	if (a->current_s == 2)
	{
		if (a->arr[0] > a->arr[1])
			swap(a, true);
	}
	else
	{
		if (a->arr[0] > a->arr[1] && a->arr[0] > a->arr[2])
			very_short_big_first(a);
		else if (a->arr[0] < a->arr[1] && a->arr[0] < a->arr[2])
			very_short_small_first(a);
		else
		{
			if (a->arr[1] > a->arr[2])
				reverse_rotate(a, true);
			else
				swap(a, true);
		}
	}
}

void	smallests_to_b(t_stack *a, t_stack *b)
{
	size_t	i;

	i = 0;
	while (i < a->max_s / 2)
	{
		print_stacks(a, b);
		find_smallest_pos(a);
		if (a->smallest_pos == 1)
		{
			swap(a, true);
			a->smallest_pos = 0;
		}
		while (a->smallest_pos != 0)
		{
			if (a->smallest_pos + 1 > a->current_s / 2)
				reverse_rotate(a, true);
			else
				rotate(a, true);
			find_smallest_pos(a);
		}
		push(b, a);
		i++;
	}
}

void	short_sort(t_stack *a, t_stack *b)
{
	if (a->max_s > 6 || a->is_sort)
		return ;
	smallests_to_b(a, b);
	very_short_sort(a);
	while (b->current_s > 0)
		push(a, b);
	print_stacks(a, b);
}
