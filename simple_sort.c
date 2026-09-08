/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serozdem <serozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 13:13:18 by serozdem          #+#    #+#             */
/*   Updated: 2026/09/07 15:22:52 by serozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
<<<<<<< HEAD
void	sort_three(t_control *ctrl)
=======

void sort_three(t_stack **stack_a)
>>>>>>> dabf65fcf9eedcb8d1a61563e063498a8158667b
{
    int x;
    int y;
    int z;

<<<<<<< HEAD
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
=======
    if (!stack_a || !*stack_a || get_stack_size(*stack_a) != 3)
        return ;

    x = (*stack_a)->value;
    y = (*stack_a)->next->value;
    z = (*stack_a)->next->next->value;

    if (x > y && y < z && x < z)
        sa(stack_a);
    else if (x > y && y > z)
    {
        sa(stack_a);
        rra(stack_a);
    }
    else if (x > y && y < z && x > z)
        ra(stack_a);
    else if (x < y && y > z && x < z)
    {
        sa(stack_a);
        ra(stack_a);
    }
    else if (x < y && y > z && x > z)
        rra(stack_a);
>>>>>>> dabf65fcf9eedcb8d1a61563e063498a8158667b
}
void simple_sort(t_stack **stack_a, t_stack **stack_b)
{
<<<<<<< HEAD
	t_stack	*min_node;
	int		pos;

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
=======
    t_stack *min_node;
    int     pos;
    int     size;

    size = get_stack_size(*stack_a);
    
    while (size > 3)
    {
        min_node = find_min(*stack_a);
        pos = get_position(*stack_a, min_node);
        
        while (*stack_a != min_node)
        {
            if (pos <= size / 2)
                ra(stack_a);
            else
                rra(stack_a);
        }
        pb(stack_a, stack_b);
        size--;
    }
    
    if (size == 2 && (*stack_a)->value > (*stack_a)->next->value)
        sa(stack_a);
    else if (size == 3 && !is_sorted(*stack_a))
    
    
        sort_three(stack_a);
        
  
    while (get_stack_size(*stack_b) > 0)
        pa(stack_a, stack_b);
>>>>>>> dabf65fcf9eedcb8d1a61563e063498a8158667b
}