/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 11:15:13 by ggilbert          #+#    #+#             */
/*   Updated: 2021/07/29 11:15:34 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *a)
{
	size_t	i;

	i = 0;
	printf("%c[", a->stack_name);
	while (i < a->max_s)
	{
		printf("%d, ", a->arr[i]);
		i++;
	}
	printf("]\t\ttop : %d", a->top_pos);
	printf("\tcurrent_s = %zu\n", a->current_s);
}

void	print_stacks(t_stack *a, t_stack *b)
{
	print_stack(a);
	print_stack(b);
}

void	print_stack_state(t_stack *a)
{
	printf("\n------------------ Stack '%c' state ---------------------\n", \
		a->stack_name);
	printf("Is stack sort : %d\n\n", a->is_sort);
	printf("Biggest value\t|\tSmallest value\n \
[] = %d\t\t|\t[%zu] = %d\n\n", a->biggest, a->smallest_pos, a->smallest);
	printf("Max stack size :\t%zu\n\
Current size :\t\t%zu\n\
Top of the stack :\t%d\n\n", a->max_s, a->current_s, a->top_pos);
	print_stack(a);
	printf("---------------------------------------------------------\n\n");
}
