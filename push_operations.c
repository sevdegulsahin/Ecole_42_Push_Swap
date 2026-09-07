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
	t_stack *temp;

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
void	pa(t_stack **a, t_stack **b, int print)
{
	push_nodes(b, a);
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, int print)
{
	push_nodes(a, b);
	if (print)
		write(1, "pb\n", 3);
}
