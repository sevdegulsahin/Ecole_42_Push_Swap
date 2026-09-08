/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serozdem <serozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:23:26 by sevdsahi          #+#    #+#             */
/*   Updated: 2026/09/08 12:28:00 by serozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	reverse_rotate_nodes(t_stack **stack)
{
	if (!stack || !*stack || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->prev;
}

void	rra(t_control *ctrl)
{
	reverse_rotate_nodes(&ctrl->a->top);
	ctrl->op_counts[OP_RRA]++;
	ctrl->total_ops++;
	write(1, "rra\n", 4);
}

void	rrb(t_control *ctrl)
{
	reverse_rotate_nodes(&ctrl->b->top);
	ctrl->op_counts[OP_RRB]++;
	ctrl->total_ops++;
	write(1, "rrb\n", 4);
}

void	rrr(t_control *ctrl)
{
	reverse_rotate_nodes(&ctrl->a->top);
	reverse_rotate_nodes(&ctrl->b->top);
	ctrl->op_counts[OP_RRR]++;
	ctrl->total_ops++;
	write(1, "rrr\n", 4);
}
