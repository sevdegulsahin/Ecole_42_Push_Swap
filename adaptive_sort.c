/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serozdem <serozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 15:48:57 by serozdem          #+#    #+#             */
/*   Updated: 2026/09/08 18:36:19 by serozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_control *ctrl, double disorder)

{
	if (disorder >= 0.5)
		radix_sort(ctrl);
	else if (disorder >= 0.2)
		sort_chunk(ctrl);
	else
		simple_sort(ctrl);
}

void	execute_sort(t_control *ctrl)
{
	if (!ctrl || !ctrl->a)
		return ;
	ctrl->disorder = calculate_disorder(ctrl->a);
	if (ctrl->a->size <= 5)
		simple_sort(ctrl);
	else if (ctrl->mode == MODE_SIMPLE)
		simple_sort(ctrl);
	else if (ctrl->mode == MODE_MEDIUM)
		sort_chunk(ctrl);
	else if (ctrl->mode == MODE_COMPLEX)
		radix_sort(ctrl);
	else
		adaptive_sort(ctrl, ctrl->disorder);
	if (ctrl->bench)
		print_bench_stats(ctrl);
}
