/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevdsahi <sevdsahi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 13:27:47 by sevdsahi          #+#    #+#             */
/*   Updated: 2026/09/01 13:39:44 by sevdsahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap_nodes(t_stack **stack)
{
	t_stack *first;
	t_stack *second;
	int temp_value;
	int temp_index;
	if (!stack || !*stack || (*stack == (*stack)->next))
		return ;
    
	first = *stack;
	second = first->next;
    
	temp_value = first->value;
	temp_index = first->index;

	first->value = second->value;
	first->index = second->index;
    
	second->value = temp->value;
	second->index = temp->index;
}
void sa(t_stack **a, int print)
{
    swap_nodes(a);
    if(print)
        write(1,"sa\n",3);
}
void sb(t_stack **b, int print)
{
    swap_nodes(b);
    if (print)
        write(1, "sb\n", 3);
}

void ss(t_stack **a, t_stack **b, int print)
{
    swap_nodes(a);
    swap_nodes(b);
    if (print)
        write(1, "ss\n", 3);
}