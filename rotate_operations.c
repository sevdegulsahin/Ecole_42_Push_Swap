/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevdsahi <sevdsahi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:28:35 by sevdsahi          #+#    #+#             */
/*   Updated: 2026/09/01 17:15:02 by sevdsahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void rotate_nodes(t_stack **stack)
{
    if (!stack || !*stack || (*stack)->next == *stack)
        return;

    *stack = (*stack)->next;
}
void ra(t_stack **a, int print)
{
    rotate_nodes(a);
    if (print)
        write(1, "ra\n", 3);
}

void rb(t_stack **b, int print)
{
    rotate_nodes(b);
    if (print)
        write(1, "rb\n", 3);
}

void rr(t_stack **a, t_stack **b, int print)
{
    rotate_nodes(a);
    rotate_nodes(b);
    if (print)
        write(1, "rr\n", 3);
}
