/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 11:36:40 by ggilbert          #+#    #+#             */
/*   Updated: 2021/07/26 16:03:42 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


//! somes troubles with push
void	push(t_stack *to, t_stack *from)
{
	//printf("\nstart push from %c to %c\n", from->stack_name, to->stack_name);
	//print_stacks(from, to);
	if (from->current_s == 0)
		return ;
	to->arr[to->top_pos] = from->arr[from->top_pos];
	from->arr[from->top_pos] = 0;
	//if (to->top_pos != 0)
	to->top_pos--;
	to->current_s++;
	if (from->top_pos != (int)from->max_s - 1)
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
