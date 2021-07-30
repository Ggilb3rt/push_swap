/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 14:52:09 by ggilbert          #+#    #+#             */
/*   Updated: 2021/07/30 16:44:01 by ggilbert         ###   ########.fr       */
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

/*void	smallest_pos_exception(t_stack *a, int *found)
{
	size_t	i;

	i = 0;
	if (found[i] == 1)
	{
		while (found[i] == 1)
		{
			i++;
			a->smallest_pos = i;
		}
	}
	else
		a->smallest_pos = 0;
	while (i <= a->max_s - 1)
	{
		//printf("found ! %d\ta[%zu]=%d\tsmall %zu\n", found[i], i, a->arr[i], a->smallest_pos);
		if (found[i] == 0)
		{
			if (a->arr[a->smallest_pos] > a->arr[i])
				a->smallest_pos = i;
		}
		i++;
	}
	//printf("smallest at the end : a[%zu]=%d\n\n", a->smallest_pos, a->arr[a->smallest_pos]);
}

//! le probleme pourrai venir de la comparaison de smallest_pos_exception
//! elle compare si i n'est pas found mais i+1 peut etre found
//! ==> c'est la merde (peut etre)

//! fonctionne mais avec des bugs +- etranges
//! le plus grand n'est jamais converti
//! quelques fois la valeur n'est pas convertie ex : 99 -8 220 1000 0 INT_MAX
//! ici 1000 n'est pas converti
//! pourtant 99 -8 220 8 converti tout le monde correctement...

void	simplify_num(t_stack *a)
{
	int		already_found[a->max_s];
	int		new_val;
	size_t	i;

	new_val = 0;
	i = 0;
	ft_memset(already_found, 0, a->max_s * sizeof(int));
	//printf("\nSIMPLIFYER %zu\n", a->max_s);
	//print_stack(a);
	while (already_found[0] == 0 || already_found[1] == 0
		|| already_found[2] == 0)
	{
		//printf("nez %d\ta[] = %d\n", new_val, a->arr[a->smallest_pos]);
		smallest_pos_exception(a, already_found);
		a->arr[a->smallest_pos] = new_val;
		already_found[a->smallest_pos] = 1;
		new_val++;
	}
	//print_stack(a);
}*/

t_bool	copy_stack(t_stack *base, t_stack *copy, char name)
{
	size_t	i;

	i = 0;
	if (!init_stack(copy, base->max_s + 1, name))
		return (false);
	while (i < base->max_s)
	{
		copy->arr[i] = base->arr[i];
		copy->current_s++;
		i++;
	}
	copy->top_pos = base->top_pos;
	copy->smallest_pos = base->smallest_pos;
	copy->smallest = base->smallest;
	return (true);
}

void	bubble_sort(t_stack *copy)
{
	int		tmp;
	size_t	i;

	i = copy->top_pos;
	while (i < copy->max_s)
	{
		find_smallest_pos(copy);
		tmp = copy->arr[copy->top_pos];
		copy->arr[copy->top_pos] = copy->arr[copy->smallest_pos];
		copy->arr[copy->smallest_pos] = tmp;
		copy->top_pos++;
		i++;
	}
}

void	insertionSort(t_stack *a)
{
	t_stack	copy;
	int		i;
	int		j;

	copy_stack(a, &copy, 't');
	bubble_sort(&copy);
	i = 0;
	while (i < (int)a->max_s)
	{
		j = 0;
		while (j < (int)copy.max_s)
		{
			if (a->arr[i] == copy.arr[j])
			{
				a->arr[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(copy.arr);
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
		my_exit(&a, &b, EXIT_SUCCESS);
	if (is_short(&a))
		my_exit(&a, &b, EXIT_SUCCESS);
	find_biggest(&a);
	find_smallest(&a);
	find_smallest_pos(&a);
	if (ac <= 4)
		very_short_sort(&a);
	else if (ac <= 7)
		short_sort(&a, &b);
	else
	{
		insertionSort(&a);
		big_sort(&a, &b);
	}
	my_exit(&a, &b, EXIT_FAILURE);
	return (0);
}
