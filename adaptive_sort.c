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
	else if (disorder < 0.5)
		medium_sort(ctrl);
	else
		radix_sort(ctrl);
}

void	execute_sort(t_control *ctrl)
{
	double	disorder;

	if (!ctrl || !ctrl->a || is_sorted(ctrl->a->top))
		return ;
	disorder = calculate_disorder(ctrl->a);
	if (ctrl->mode == 1)
		simple_sort(ctrl);
	else if (ctrl->mode == 2)
		medium_sort(ctrl);
	else if (ctrl->mode == 3)
		radix_sort(ctrl);
	else
		adaptive_sort(ctrl, disorder);
	if (ctrl->bench)
		print_bench_stats(ctrl, disorder);
}