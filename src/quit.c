/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:27:28 by ggilbert          #+#    #+#             */
/*   Updated: 2021/07/27 15:28:19 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	my_exit(t_stack *a, t_stack *b, int status)
{
	if (a->arr)
		free(a->arr);
	if (b->arr)
		free(b->arr);
	exit(status);
}
