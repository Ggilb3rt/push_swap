/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 11:36:40 by ggilbert          #+#    #+#             */
/*   Updated: 2021/07/27 13:50:42 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *to, t_stack *from)
{
	if (from->current_s == 0)
		return ;
	to->top_pos--;
	to->arr[to->top_pos] = from->arr[from->top_pos];
	from->arr[from->top_pos] = 0;
	to->current_s++;
	if (from->top_pos != (int)from->max_s)
		from->top_pos++;
	from->current_s--;
	ft_putchar_fd('p', 1);
	ft_putchar_fd(to->stack_name, 1);
	ft_putchar_fd('\n', 1);
}

void	push_a(t_stack *a, t_stack *b)
{
	if (b->current_s == 0)
		return ;
	a->arr[a->top_pos] = b->arr[b->top_pos];
	a->top_pos += 1;
	a->current_s += 1;
	b->arr[b->top_pos] = 0;
	b->top_pos += 1;
	b->current_s -= 1;
	ft_putstr_fd("pb2\n", 1);
	print_stacks(a, b);
}
