/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:56:59 by ggilbert          #+#    #+#             */
/*   Updated: 2021/07/26 14:39:45 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *x, t_bool single)
{
	int	tmp;

	if (x->current_s <= 1)
		return ;
	tmp = x->arr[x->top_pos + 1];
	x->arr[x->top_pos + 1] = x->arr[x->top_pos];
	x->arr[x->top_pos] = tmp;
	if (single)
	{
		ft_putchar_fd('s', 1);
		ft_putchar_fd(x->stack_name, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	double_swap(t_stack *a, t_stack *b)
{
	swap(a, false);
	swap(b, false);
	ft_putstr_fd("ss\n", 1);
}
