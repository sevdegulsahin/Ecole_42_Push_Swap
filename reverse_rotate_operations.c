/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serozdem <serozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:23:26 by sevdsahi          #+#    #+#             */
/*   Updated: 2026/09/02 11:08:57 by serozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void reverse_rotate_nodes(t_stack **stack)
{
    if (!stack || !*stack || (*stack)->next == *stack)
        return;
    *stack=(*stack)->prev;
}
void rra(t_stack **a, int print)
{
    reverse_rotate_nodes(a);
    if (print)
        write(1, "rra\n", 4);
}

void rrb(t_stack **b, int print)
{
    reverse_rotate_nodes(b);
    if (print)
        write(1, "rrb\n", 4);
}

void rrr(t_stack **a, t_stack **b, int print)
{
    reverse_rotate_nodes(a);
    reverse_rotate_nodes(b);
    if (print)
        write(1, "rrr\n", 4);
}
