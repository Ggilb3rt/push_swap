/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 14:52:21 by ggilbert          #+#    #+#             */
/*   Updated: 2021/08/04 12:41:04 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../lib/libft/libft.h"

// A retirer
//# include <string.h>
//# include <stdio.h>

typedef struct s_stack
{
	int				*arr;
	int				biggest;
	int				smallest;
	size_t			smallest_pos;
	int				top_pos;
	size_t			max_s;
	size_t			current_s;
	t_bool			is_sort;
	char			stack_name;
}				t_stack;

//void	print_stack(t_stack *a);
//void	print_stacks(t_stack *a, t_stack *b);
//void	print_stack_state(t_stack *a);

t_bool	init_stack(t_stack *x, int max_size, char stack_name);
t_bool	init_arg(t_stack *a, char **av);
t_bool	is_short(t_stack *x);
void	find_biggest(t_stack *x);
void	find_smallest(t_stack *x);
void	find_smallest_pos(t_stack *x);

void	swap(t_stack *x, t_bool single);
void	double_swap(t_stack *a, t_stack *b);
void	push(t_stack *to, t_stack *from);
void	rotate(t_stack *x, t_bool single);
void	double_rotate(t_stack *a, t_stack *b);
void	reverse_rotate(t_stack *x, t_bool single);
void	double_reverse_rotate(t_stack *a, t_stack *b);

t_bool	stack_normalizer(t_stack *a);
void	very_short_sort(t_stack *a);
void	short_sort(t_stack *a, t_stack *b);
void	big_sort(t_stack *a, t_stack *b);

void	my_exit(t_stack *a, t_stack *b, int status);

#endif