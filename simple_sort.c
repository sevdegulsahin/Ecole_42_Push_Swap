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

void sort_three(t_stack **stack_a)
{
    int x;
    int y;
    int z;

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
}
void simple_sort(t_stack **stack_a, t_stack **stack_b)
{
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
}