/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 14:52:09 by ggilbert          #+#    #+#             */
/*   Updated: 2021/07/26 12:44:54 by ggilbert         ###   ########.fr       */
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

/*
    ac = 1 ==> return(0)

    check av :
        - que des int
TODO    - pas de depassement d'int
        - pas de doublon
    ERROR handler == "Error\n"

    select method based on ac
    ?   - ac <= 5 ==> short small stack
	?	- ac > 5 ==> short big stack

	use good method and print each actions
*/

int	main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;

	if (ac == 1)
		return (EXIT_SUCCESS);
	if (!init_stack(&a, ac, 'a') || !init_stack(&b, ac, 'b'))
		return (EXIT_FAILURE);
	//! return after here need to free a and b
	if (!init_arg(a.max_s, av, a.arr, &a.current_s, &a.top_pos))
		return (EXIT_FAILURE);
	if (is_short(&a))
		return (EXIT_SUCCESS);
	find_biggest(&a);
	find_smallest(&a);
	swap(&a, true);
	push(&b, &a);
	push(&b, &a);
	push(&b, &a);
	push(&b, &a);
	push(&b, &a);
	print_stack(&a, a.max_s);
	print_stack(&b, b.max_s);
	free(a.arr);
	free(b.arr);
	return (EXIT_SUCCESS);
}
