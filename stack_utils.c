/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serozdem <serozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 11:37:36 by serozdem          #+#    #+#             */
/*   Updated: 2026/09/03 19:01:08 by serozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position(t_stack *stack, t_stack *target)
{
	t_stack	*temp;
	int		pos;
	int		size;

	if (!stack || !target)
		return (-1);
	size = get_stack_size(stack);
	temp = stack;
	pos = 0;
	while (pos < size)
	{
		if (temp == target)
			return (pos);
		temp = temp->next;
		pos++;
	}
	return (-1);
}
void	indexing(t_stack_info *stack_a)
{
	t_stack *cur;
	t_stack *cmp;

	if (!stack_a || !stack_a->top)
		return ;
	cur = stack_a->top;
	while (1)
	{
		cur->index = 0;
		cmp = stack_a->top;
		while (1)
		{
			if (cmp->value < cur->value)
				cur->index++;
			cmp = cmp->next;
			if (cmp == stack_a->top)
				break ;
		}
		cur = cur->next;
		if (cur == stack_a->top)
			break ;
	}
}

int	add_node_back(t_stack_info *stack, int value)
{
	t_stack	*new_node;
	t_stack	*tail;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (0);
	new_node->value = value;
	new_node->index = 0;
	if (!stack->top)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		stack->top = new_node;
	}
	else
	{
		tail = stack->top->prev;
		tail->next = new_node;
		new_node->prev = tail;
		new_node->next = stack->top;
		stack->top->prev = new_node;
	}
	stack->size++;
	return (1);
}