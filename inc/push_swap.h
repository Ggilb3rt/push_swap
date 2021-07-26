/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 14:52:21 by ggilbert          #+#    #+#             */
/*   Updated: 2021/07/26 15:48:09 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../lib/libft/libft.h"

// A retirer
# include <string.h>
# include <stdio.h>

typedef struct s_stack
{
	int				*arr;
	int				biggest;
	int				smallest;
	int				top_pos;
	size_t			max_s;
	size_t			current_s;
	t_bool			is_sort;
	char			stack_name;
}				t_stack;

void	print_stack(t_stack *a, int l);
void	print_stacks(t_stack *a, t_stack *b);
void	push_a(t_stack *a, t_stack *b);

t_bool	init_stack(t_stack *x, int max_size, char stack_name);
t_bool	init_arg(int max_l, char **av, int *a, size_t *current_s, int *top_pos);
t_bool	is_short(t_stack *x);
void	find_biggest(t_stack *x);
void	find_smallest(t_stack *x);

void	swap(t_stack *x, t_bool single);
void	double_swap(t_stack *a, t_stack *b);
void	push(t_stack *to, t_stack *from);
void	rotate(t_stack *x, t_bool single);
void	double_rotate(t_stack *a, t_stack *b);
void	reverse_rotate(t_stack *x, t_bool single);
void	double_reverse_rotate(t_stack *a, t_stack *b);

#endif