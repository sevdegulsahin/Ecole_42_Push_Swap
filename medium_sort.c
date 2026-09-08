/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serozdem <serozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 17:40:43 by serozdem          #+#    #+#             */
/*   Updated: 2026/09/03 19:38:42 by serozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
 int	get_chunk_size(int total_size)
{
	int	root;

	if (total_size <= 0)
		return (0);
	root = 1;
	while (root * root <= total_size)
		root++;
	return (((root - 1) * 3) / 2);
}

 int	find_index_position(t_stack *b_top, int target_index)
{
	int	position;

	position = 0;
	while (b_top != NULL)
	{
		if (b_top->index == target_index)
			return (position);
		b_top = b_top->next;
		position++;
	}
	return (-1);
}

void	push_chunk_to_b(t_control *ctrl, int min_bound, int max_bound)
{
	int	current_index;

	current_index = ctrl->a->top->index;
	if (current_index <= min_bound)
	{
		pb(ctrl);
		rb(ctrl);
	}
	else if (current_index <= max_bound)
		pb(ctrl);
	else
		ra(ctrl);
}

void	push_back_to_a(t_control *ctrl)
{
	int	b_size;
	int	target_index;
	int	position;

	while (ctrl->b->size > 0)
	{
		b_size = ctrl->b->size;
		target_index = b_size - 1;
		position = find_index_position(ctrl->b->top, target_index);
		if (position == -1)
			break ;
		if (position <= b_size / 2)
		{
			while (ctrl->b->top->index != target_index)
				rb(ctrl);
		}
		else
		{
			while (ctrl->b->top->index != target_index)
				rrb(ctrl);
		}
		pa(ctrl);
	}
}

void	sort_chunk(t_control *ctrl)
{
	int	min_bound;
	int	max_bound;
	int	chunk_size;
	int	total_size;

	if (ctrl->mode == 0)
		ctrl->adaptive_checker = 2;
	indexing(ctrl->a);
	min_bound = 0;
	total_size = ctrl->a->size;
	chunk_size = get_chunk_size(total_size);
	max_bound = chunk_size;
	while (ctrl->a->size > 0)
	{
		push_chunk_to_b(ctrl, min_bound, max_bound);
		if (ctrl->b->size > 1 && ctrl->b->size > min_bound
			&& max_bound < total_size - 1)
		{
			min_bound++;
			max_bound++;
		}
	}
	push_back_to_a(ctrl);
}