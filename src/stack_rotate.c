/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:58:56 by ggilbert          #+#    #+#             */
/*   Updated: 2021/07/26 15:05:13 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *x, t_bool single)
{
	int		tmp;
	size_t	i;

	tmp = x->arr[x->top_pos];
	i = (size_t)x->top_pos;
	while (i < x->max_s - 1)
	{
		x->arr[i] = x->arr[i + 1];
		i++;
	}
	x->arr[x->max_s - 1] = tmp;
	if (single)
	{
		ft_putchar_fd('r', 1);
		ft_putchar_fd(x->stack_name, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	double_rotate(t_stack *a, t_stack *b)
{
	rotate(a, false);
	rotate(b, false);
	ft_putstr_fd("rr\n", 1);
}


void	reverse_rotate(t_stack *x, t_bool single)
{
	int		tmp;
	size_t	i;

	tmp = x->arr[x->max_s - 1];
	i = x->max_s - 1;
	while (i > (size_t)x->top_pos)
	{
		x->arr[i] = x->arr[i - 1];
		i--;
	}
	x->arr[x->top_pos] = tmp;
	if (single)
	{
		ft_putstr_fd("rr", 1);
		ft_putchar_fd(x->stack_name, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	double_reverse_rotate(t_stack *a, t_stack *b)
{
	reverse_rotate(a, false);
	reverse_rotate(b, false);
	ft_putstr_fd("rrr\n", 1);
}
