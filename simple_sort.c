/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serozdem <serozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 13:13:18 by serozdem          #+#    #+#             */
/*   Updated: 2026/09/08 18:35:30 by serozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_control *ctrl)
{
	int	x;
	int	y;
	int	z;

	if (!ctrl->a || ctrl->a->size != 3)
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
	t_stack *min_node;
	int pos;

	if (!ctrl || !ctrl->a || is_sorted(ctrl->a->top))
		return ;
	if (ctrl->a->size == 2)
	{
		if (ctrl->a->top->value > ctrl->a->top->next->value)
			sa(ctrl);
		return ;
	}
	while (ctrl->a->size > 3)
	{
		min_node = find_min(ctrl->a->top);
		pos = get_position(ctrl->a->top, min_node);
		while (ctrl->a->top != min_node)
		{
			if (pos <= ctrl->a->size / 2)
				ra(ctrl);
			else
				rra(ctrl);
		}
		pb(ctrl);
	}
	sort_three(ctrl);
	while (ctrl->b->size > 0)
		pa(ctrl);
}