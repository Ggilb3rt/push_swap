/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 14:52:09 by ggilbert          #+#    #+#             */
/*   Updated: 2021/08/01 15:14:29 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**split_av(int ac, char **av)
{
	char	**new_av;
	int		i;

	i = 1;
	new_av = malloc(sizeof(new_av) * ac);
	while (i < ac)
	{
		new_av = ft_split(av[i], ' ');
		i++;
	}
	return (new_av);
}

int	main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;

	if (ac == 1)
		return (EXIT_SUCCESS);
	if (!init_stack(&a, ac, 'a'))
		return (EXIT_FAILURE);
	if (!init_stack(&b, ac, 'b'))
		my_exit(&a, &b, EXIT_FAILURE);
	if (!init_arg(&a, av))
		my_exit(&a, &b, EXIT_SUCCESS);
	if (is_short(&a))
		my_exit(&a, &b, EXIT_SUCCESS);
	if (ac <= 4)
		very_short_sort(&a);
	else if (ac <= 7)
		short_sort(&a, &b);
	else
	{
		if (!stack_normalizer(&a))
			my_exit(&a, &b, EXIT_FAILURE);
		big_sort(&a, &b);
	}
	my_exit(&a, &b, EXIT_SUCCESS);
	return (0);
}
