/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 14:52:09 by ggilbert          #+#    #+#             */
/*   Updated: 2021/07/29 17:21:40 by ggilbert         ###   ########.fr       */
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

void	smallest_pos_exception(t_stack *a, int *found)
{
	size_t	i;

	i = 0;
	while (i <= a->max_s - 1)
	{
		//printf("found ! %d\n", found[i]);
		if (!found[i])
		{
			if (a->arr[a->smallest_pos] > a->arr[i])
				a->smallest_pos = i;
		}
		i++;
	}
}

//! fonctionne mais ne prends pas les valeurs 0 1 2 3 etc
//! mais les valeurs 0 (biggest+1) (biggest+2) etc
//! gros probleme pour INT_MAX

//! le probleme pourrai venir de la comparaison de smallest_pos_exception
//! elle compare si i n'est pas found mais i+1 peut etre found
//! ==> c'est la merde (peut etre)
void	simplify_num(t_stack *a)
{
	int		already_found[a->max_s];
	int		new_val;
	size_t	i;

	new_val = 0;
	i = 0;
	ft_memset(already_found, 0, a->max_s * sizeof(int));
	//printf("\nSIMPLIFYER %zu\n", a->max_s);
	print_stack(a);
	while (already_found[0] == 0 || already_found[1] == 0
		|| already_found[2] == 0)
	{
	//	printf("nez %d\ta[] = %d\n", new_val, a->arr[a->smallest_pos]);
		smallest_pos_exception(a, already_found);
		a->arr[a->smallest_pos] = new_val;
		already_found[a->smallest_pos] = 1;
		new_val++;
	}
	print_stack(a);
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

	simplify_num(&a);

	//print_stack_state(&a);
	if (ac <= 4)
		very_short_sort(&a);
	else if (ac <= 7)
		short_sort(&a, &b);
	//else
	//	big_sort(&a, &b);
	//print_stack_state(&a);
	my_exit(&a, &b, EXIT_FAILURE);
}
