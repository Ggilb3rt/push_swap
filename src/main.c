/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 14:52:09 by ggilbert          #+#    #+#             */
/*   Updated: 2021/07/29 11:23:46 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_some(t_stack *a, t_stack *b)
{
	const int	x_time = 7;
	int			i;

	i = 0;
	swap(a, true);
	while (i++ < x_time)
		rotate(a, true);
	i = 0;
	while (i++ < x_time)
		reverse_rotate(a, true);
	i = 0;
	while (i++ < x_time)
		push(b, a);
	i = 0;
	while (i++ < x_time)
		rotate(b, true);
	i = 0;
	swap(b, true);
	i = 0;
	while (i++ < x_time / 2)
		push(a, b);
	double_rotate(a, b);
}

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
	
	//char **new_av;
	/*new_av = split_av(ac, av);
	for (int i = 0; new_av[i] != NULL; i++)
		printf("New av[i] = %s\n", new_av[i]);
	*/
	if (ac == 1)
		return (EXIT_SUCCESS);
	if (!init_stack(&a, ac, 'a') || !init_stack(&b, ac, 'b'))
		return (EXIT_FAILURE);
	if (!init_arg(&a, av))
		my_exit(&a, &b, EXIT_FAILURE);
	if (is_short(&a))
		my_exit(&a, &b, EXIT_SUCCESS);
	find_biggest(&a);
	find_smallest(&a);
	find_smallest_pos(&a);
	//print_stack_state(&a);
	if (ac <= 4)
		very_short_sort(&a);
	else
		short_sort(&a, &b);
	//print_stack_state(&a);
	my_exit(&a, &b, EXIT_FAILURE);
}
