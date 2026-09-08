/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serozdem <serozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 13:27:47 by sevdsahi          #+#    #+#             */
/*   Updated: 2026/09/08 18:35:37 by serozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	swap_nodes(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	int		temp_value;
	int		temp_index;

	if (!stack || !*stack || (*stack == (*stack)->next))
		return ;
	first = *stack;
	second = first->next;
	temp_value = first->value;
	temp_index = first->index;
	first->value = second->value;
	first->index = second->index;
	second->value = temp_value;
	second->index = temp_index;
}

void	sa(t_control *ctrl)
{
	swap_nodes(&ctrl->a->top);
	ctrl->op_counts[OP_SA]++;
	ctrl->total_ops++;
	write(1, "sa\n", 3);
}

void	sb(t_control *ctrl)
{
	swap_nodes(&ctrl->b->top);
	ctrl->op_counts[OP_SB]++;
	ctrl->total_ops++;
	write(1, "sb\n", 3);
}

void	ss(t_control *ctrl)
{
	swap_nodes(&ctrl->a->top);
	swap_nodes(&ctrl->b->top);
	ctrl->op_counts[OP_SS]++;
	ctrl->total_ops++;
	write(1, "ss\n", 3);
}