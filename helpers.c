/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevdsahi <sevdsahi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:37:04 by sevdsahi          #+#    #+#             */
/*   Updated: 2026/09/01 18:28:42 by sevdsahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int is_sorted(t_stack *stack)
{
    t_stack *current;
    if(!stack || stack->next == stack)
        return (1);
    
    current = stack;
    
    while(current->next != stack)
    {
        if(current->value > current->next->value)
            return (0);
        
        current=current->next;
    }
    return (1);
}

t_stack *find_min(t_stack *stack)
{
    t_stack *current;
    t_stack *min_node;

    if (!stack)
        return (NULL);

    min_node = stack;          
    current = stack->next;   

    // Çember tamamlanana kadar dön
    while (current != stack)
    {
        if (current->value < min_node->value)
            min_node = current; 
        current = current->next;
    }
    return (min_node); 
}

t_stack *find_max(t_stack *stack)
{
    t_stack *current;
    t_stack *max_node;

    if (!stack)
        return (NULL);

    max_node = stack;
    current = stack->next;

    while (current != stack)
    {
        if (current->value > max_node->value)
            max_node = current; 
        current = current->next;
    }
    return (max_node);
}
int get_stack_size(t_stack *stack)
{
    t_stack *current;
    int     count;

    if (!stack)
        return (0);
    count = 1;
    current = stack->next;

    while (current != stack)
    {
        count++;
        current = current->next;
    }
    return (count);
}
int has_duplicate(t_stack *stack)
{
    t_stack *current;
    t_stack *check;

    if (!stack || stack->next == stack)
        return (0);

    current = stack;
    
    while (1)
    {
        check = current->next; 
        while (check != current)
        {
            if (current->value == check->value)
                return (1); 
            check = check->next;
        }
        
        current = current->next;
        
        if (current == stack)
            break;
    }
    return (0); 
}
