/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serozdem <serozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 15:48:57 by serozdem          #+#    #+#             */
/*   Updated: 2026/09/03 21:27:33 by serozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_control *ctrl, double disorder)
{
	if (disorder < 0.2)
		simple_sort(ctrl);
	else
		sort_chunk(ctrl);
}

void	execute_sort(t_control *ctrl)
{
	double	disorder;
	int		size;

	if (!ctrl || !ctrl->a || is_sorted(ctrl->a->top))
		return ;
	disorder = calculate_disorder(ctrl->a);
	ctrl->disorder = disorder;
	size = ctrl->a->size;
	if (ctrl->mode == MODE_SIMPLE)
	{
		simple_sort(ctrl);
		return ;
	}
	if (ctrl->mode == MODE_MEDIUM)
	{
		sort_chunk(ctrl);
		return ;
	}
	if (ctrl->mode == MODE_COMPLEX)
	{
		radix_sort(ctrl);
		return ;
	}
	if (size <= 5)
	{
		simple_sort(ctrl);
		return ;
	}
	adaptive_sort(ctrl, disorder);
}
