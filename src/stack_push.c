/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 11:36:40 by ggilbert          #+#    #+#             */
/*   Updated: 2021/08/01 14:53:48 by ggilbert         ###   ########.fr       */
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
	ft_putchar_fd('p', STDOUT_FILENO);
	ft_putchar_fd(to->stack_name, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}
