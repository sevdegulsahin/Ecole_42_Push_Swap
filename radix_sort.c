/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serozdem <serozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 11:27:02 by serozdem          #+#    #+#             */
/*   Updated: 2026/09/03 14:14:04 by serozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	get_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_control *ctrl)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	if (!ctrl || !ctrl->a || is_sorted(ctrl->a->top))
		return ;
	indexing(ctrl->a);
	size = get_stack_size(ctrl->a->top);
	max_bits = get_max_bits(size);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((ctrl->a->top->index >> i) & 1) == 0)
				pb(ctrl);
			else
				ra(ctrl);
			j++;
		}
		while (ctrl->b && ctrl->b->top)
			pa(ctrl);
		i++;
	}
}
