/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 14:52:09 by ggilbert          #+#    #+#             */
/*   Updated: 2021/07/27 13:45:56 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *a, int l)
{
	int	i;

	i = 0;
	printf("%c[", a->stack_name);
	while (i < l)
	{
		printf("%d, ", a->arr[i]);
		i++;
	}
	printf("]\t\ttop : %d", a->top_pos);
	printf("\tcurrent_s = %zu\n", a->current_s);
}

void	print_stacks(t_stack *a, t_stack *b)
{
	print_stack(a, a->max_s);
	print_stack(b, b->max_s);
}

/*
    ac = 1 ==> return(0)

    check av :
        - que des int
		- pas de depassement d'int
        - pas de doublon
    ERROR handler == "Error\n"
	============ OK ============

    select method based on ac
    ?   - ac <= 5 ==> short small stack
	?	- ac > 5 ==> short big stack

	use good method and print each actions
*/

void	do_some(t_stack *a, t_stack *b)
{
	const int x_time = 7;
	int i;

	i = 0;
	swap(a, true);
	print_stacks(a, b);
	while (i++ < x_time)
		rotate(a, true);
	print_stacks(a, b);
	i = 0;
	while (i++ < x_time)
		reverse_rotate(a, true);
	print_stacks(a, b);
	i = 0;
	while (i++ < x_time)
		push(b, a);
	print_stacks(a, b);
	i = 0;
	while (i++ < x_time)
		rotate(b, true);
	print_stacks(a, b);
	i = 0;
	swap(b, true);
	print_stacks(a, b);
	i = 0;
	while (i++ < x_time / 2)
		push(a, b);
	print_stacks(a, b);
	double_rotate(a, b);
}

void	make_ex(t_stack *a, t_stack *b)
{
	swap(a, true);
	print_stacks(a, b);
	push(b, a);push(b, a);push(b, a);
	print_stacks(a, b);
	double_rotate(a, b);
	print_stacks(a, b);
	double_reverse_rotate(a, b);
	print_stacks(a, b);
	swap(a, true);
	print_stacks(a, b);
	push(a, b);push(a, b);push(a, b);
	print_stacks(a, b);
}

int	main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;

	if (ac == 1)
		return (EXIT_SUCCESS);
	if (!init_stack(&a, ac, 'a') || !init_stack(&b, ac, 'b'))
		return (EXIT_FAILURE);
	//! return after here need to free a and b
	if (!init_arg(&a, av))
		return (EXIT_FAILURE);
	if (is_short(&a))
		return (EXIT_SUCCESS);
	find_biggest(&a);
	find_smallest(&a);
	//make_ex(&a, &b);
	do_some(&a, &b);
	ft_putstr_fd("\nEND\n", 1);
	print_stacks(&a, &b);
	free(a.arr);
	free(b.arr);
	return (EXIT_SUCCESS);
}
