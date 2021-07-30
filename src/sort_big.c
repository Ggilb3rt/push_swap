/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 09:23:33 by ggilbert          #+#    #+#             */
/*   Updated: 2021/07/30 16:27:50 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	showbits(int x )
{
	int	i;

	i = 0;
	for (i = (sizeof(int) * 4) - 1; i >= 0; i--)
	{
		ft_putchar_fd(x & (1u << i) ? '1' : '0', 1);
	}
	printf("\n");
}

void preprint(t_stack *a)
{
	for (size_t i = 0; i < a->max_s; i++)
	{
		showbits(a->arr[i]);
	}
}

void	big_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	bin;

	max_bits = 0;
	while ((a->biggest >> max_bits) != 0)
		++max_bits;
	for (int i = 0; i <= max_bits; i++)
	{
		for (size_t j = 0; j < a->max_s; j++)
		{
			bin = (a->arr[a->top_pos] >> i) & 1;
			if (bin == 1)
				rotate(a, true);
			else
				push(b, a);
		}
		while (b->current_s != 0)
			push(a, b);
	}
}
