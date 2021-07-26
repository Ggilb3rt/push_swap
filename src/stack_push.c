/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 11:36:40 by ggilbert          #+#    #+#             */
/*   Updated: 2021/07/26 12:35:54 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *to, t_stack *from)
{
	if (from->current_s == 0)
		return ;
	to->arr[to->top_pos] = from->arr[from->top_pos];
	from->arr[from->top_pos] = 0;
	to->top_pos--;
	to->current_s++;
	from->top_pos++;
	from->current_s--;
	ft_putchar_fd('p', 1);
	ft_putchar_fd(to->stack_name, 1);
	ft_putchar_fd('\n', 1);
}
