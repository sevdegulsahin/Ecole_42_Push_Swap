/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serozdem <serozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 13:40:58 by sevdsahi          #+#    #+#             */
/*   Updated: 2026/09/03 14:25:11 by serozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_nodes(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	if (!src || !*src || !dest)
		return ;
	temp = *src;
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	if (temp->next == temp)
		*src = NULL;
	else
		*src = temp->next;
	if (!*dest)
	{
		temp->next = temp;
		temp->prev = temp;
	}
	else
	{
		temp->next = *dest;
		temp->prev = (*dest)->prev;
		temp->prev->next = temp;
		(*dest)->prev = temp;
	}
	*dest = temp;
}

void	pa(t_control *ctrl)
{
	if (!ctrl->b->top)
		return ;
	push_nodes(&ctrl->b->top, &ctrl->a->top);
	ctrl->a->size++;
	ctrl->b->size--;
	write(1, "pa\n", 3);
	ctrl->op_counts[OP_PA]++;
	ctrl->total_ops++;
}

void	pb(t_control *ctrl)
{
	if (!ctrl->a->top)
		return ;
	push_nodes(&ctrl->a->top, &ctrl->b->top);
	ctrl->a->size--;
	ctrl->b->size++;
	write(1, "pb\n", 3);
	ctrl->op_counts[OP_PB]++;
	ctrl->total_ops++;
}
