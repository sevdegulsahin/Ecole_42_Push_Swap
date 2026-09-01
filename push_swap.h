/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevdsahi <sevdsahi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 13:58:59 by sevdsahi          #+#    #+#             */
/*   Updated: 2026/09/01 14:38:27 by sevdsahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_stack
{
    int             value;
    int             index;
    struct s_stack   *next;
    struct s_stack   *prev;
}   t_stack ;

int is_sorted(t_stack *stack);