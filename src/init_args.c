/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:23:27 by ggilbert          #+#    #+#             */
/*   Updated: 2021/08/01 14:55:09 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	all_digits(char *av)
{
	int	k;

	k = 0;
	while (av[k])
	{
		if (!ft_isdigit(av[k]))
			if (!(k == 0 && (av[k] == '-' || av[k] == '+')))
				return (false);
		k++;
	}
	return (true);
}

t_bool	arg_overflow(int num, char *av)
{
	char	*comp;

	comp = ft_itoa(num);
	if (av[0] == '+')
		av++;
	if (strcmp(comp, av))
	{
		if (comp)
			free(comp);
		return (true);
	}
	if (comp)
		free(comp);
	return (false);
}

t_bool	put_to_a(int max_l, char **av, int *a)
{
	int	i;

	i = 1;
	while (i <= max_l)
	{
		if (!all_digits(av[i]))
			return (false);
		a[i - 1] = ft_atoi(av[i]);
		if (arg_overflow(a[i - 1], av[i]))
			return (false);
		i++;
	}
	return (true);
}

t_bool	find_double(int max_l, int *a)
{
	int	i;
	int	j;

	i = 0;
	while (i <= max_l)
	{
		j = i + 1;
		while (j < max_l)
		{
			if (a[i] == a[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

t_bool	init_arg(t_stack *a, char **av)
{
	if (!put_to_a(a->max_s, av, a->arr))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (false);
	}
	if (find_double(a->max_s, a->arr))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (false);
	}
	a->current_s = a->max_s;
	a->top_pos = 0;
	find_biggest(a);
	find_smallest(a);
	find_smallest_pos(a);
	return (true);
}
