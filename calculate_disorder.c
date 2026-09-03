/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_disorder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serozdem <serozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 15:28:55 by serozdem          #+#    #+#             */
/*   Updated: 2026/09/03 15:48:21 by serozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	calculate_disorder(t_stack_info *a)
{
	t_stack	*i_node;
	t_stack	*j_node;
	long	mistakes;
	long	total_pairs;

	if (!a || a->size <= 1)
		return (0.0);
	mistakes = 0;
	total_pairs = ((long)a->size * (a->size - 1)) / 2;
	i_node = a->top;
	while (i_node)
	{
		j_node = i_node->next;
		while (j_node)
		{
			if (i_node->index > j_node->index)
				mistakes++;
			j_node = j_node->next;
		}
		i_node = i_node->next;
	}
	return ((double)mistakes / (double)total_pairs);
}