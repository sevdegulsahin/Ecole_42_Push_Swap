/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serozdem <serozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:28:35 by sevdsahi          #+#    #+#             */
/*   Updated: 2026/09/08 18:35:24 by serozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	rotate_nodes(t_stack **stack)
{
	if (!stack || !*stack || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->next;
}

void	ra(t_control *ctrl)
{
	rotate_nodes(&ctrl->a->top);
	ctrl->op_counts[OP_RA]++;
	ctrl->total_ops++;
	write(1, "ra\n", 3);
}

void	rb(t_control *ctrl)
{
	rotate_nodes(&ctrl->b->top);
	ctrl->op_counts[OP_RB]++;
	ctrl->total_ops++;
	write(1, "rb\n", 3);
}

void	rr(t_control *ctrl)
{
	rotate_nodes(&ctrl->a->top);
	rotate_nodes(&ctrl->b->top);
	ctrl->op_counts[OP_RR]++;
	ctrl->total_ops++;
	write(1, "rr\n", 3);
}
