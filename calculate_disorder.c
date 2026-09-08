/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_disorder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serozdem <serozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 15:28:55 by serozdem          #+#    #+#             */
/*   Updated: 2026/09/07 14:12:47 by serozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

 double	count_mistakes(t_stack_info *a)
{
	t_stack	*i_node;
	t_stack	*j_node;
	int		i;
	int		j;
	double	mistakes;

	mistakes = 0.0;
	i_node = a->top;
	i = 0;
	while (i < a->size - 1)
	{
		j_node = i_node->next;
		j = i + 1;
		while (j < a->size)
		{
			if (i_node->value > j_node->value)
				mistakes += 1.0;
			j_node = j_node->next;
			j++;
		}
		i_node = i_node->next;
		i++;
	}
	return (mistakes);
}

double	calculate_disorder(t_stack_info *a)
{
	double	mistakes;
	double	total_pairs;

	if (!a || a->size <= 1)
		return (0.0);
<<<<<<< HEAD
	total_pairs = ((double)a->size * (double)(a->size - 1)) / 2.0;
	mistakes = count_mistakes(a);
	return (mistakes / total_pairs);
=======
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
>>>>>>> dabf65fcf9eedcb8d1a61563e063498a8158667b
}