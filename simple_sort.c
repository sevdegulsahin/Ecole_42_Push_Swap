/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serozdem <serozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 13:13:18 by serozdem          #+#    #+#             */
/*   Updated: 2026/09/03 21:23:00 by serozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_control *ctrl)
{
	int	x;
	int	y;
	int	z;

	if (!ctrl->a->top || get_stack_size(ctrl->a->top) != 3)
		return ;
	x = ctrl->a->top->value;
	y = ctrl->a->top->next->value;
	z = ctrl->a->top->next->next->value;
	if (x > y && y < z && x < z)
		sa(ctrl);
	else if (x > y && y > z)
	{
		sa(ctrl);
		rra(ctrl);
	}
	else if (x > y && y < z && x > z)
		ra(ctrl);
	else if (x < y && y > z && x < z)
	{
		sa(ctrl);
		ra(ctrl);
	}
	else if (x < y && y > z && x > z)
		rra(ctrl);
}

void	simple_sort(t_control *ctrl)
{
	t_stack	*min_node;
	int		pos;
	int		size;

	size = ctrl->a->size;
	while (size > 3)
	{
		min_node = find_min(ctrl->a->top);
		while (ctrl->a->top != min_node)
		{
			pos = get_position(ctrl->a->top, min_node);
			if (pos <= size / 2)
				ra(ctrl);
			else
				rra(ctrl);
		}
		pb(ctrl);
		size--;
	}
	if (size == 2 && ctrl->a->top->value > ctrl->a->top->next->value)
		sa(ctrl);
	else if (size == 3 && !is_sorted(ctrl->a->top))
		sort_three(ctrl);
	while (ctrl->b->size > 0)
		pa(ctrl);
}
