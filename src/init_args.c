/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:23:27 by ggilbert          #+#    #+#             */
/*   Updated: 2021/07/26 12:30:32 by ggilbert         ###   ########.fr       */
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
			if (!(k == 0 && av[k] == '-'))
				return (false);
		k++;
	}
	return (true);
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

t_bool	init_arg(int max_l, char **av, int *a, size_t *current_s, int *top_pos)
{
	if (!put_to_a(max_l, av, a))
	{
		write(2, "Error\n", 6);
		return (false);
	}
	if (find_double(max_l, a))
	{
		write(2, "Error\n", 6);
		return (false);
	}
	*current_s = (size_t)max_l;
	*top_pos = 0;
	return (true);
}
