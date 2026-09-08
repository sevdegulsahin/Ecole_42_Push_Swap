/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helpers_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serozdem <serozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 15:46:49 by serozdem          #+#    #+#             */
/*   Updated: 2026/09/08 16:01:54 by serozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	print_disorder(double d, int fd)
{
	int		int_part;
	int		dec_part;
	char	dec_buf[3];

	d = d * 100.0;
	int_part = (int)d;
	dec_part = (int)((d - (double)int_part) * 100.0 + 0.5);
	if (dec_part >= 100)
	{
		dec_part = 0;
		int_part++;
	}
	ft_putnbr_fd(int_part, fd);
	write(fd, ".", 1);
	dec_buf[0] = '0' + dec_part / 10;
	dec_buf[1] = '0' + dec_part % 10;
	dec_buf[2] = '\0';
	write(fd, dec_buf, 2);
	write(fd, "%", 1);
}

void	print_strategy(t_control *ctrl)
{
	write(2, "[bench] Strategy: ", 18);
	if (ctrl->a && ctrl->a->size <= 5)
		ft_putendl_fd("Simple (O(n^2))", 2);
	else if (ctrl->mode == MODE_SIMPLE)
		ft_putendl_fd("Simple (O(n^2))", 2);
	else if (ctrl->mode == MODE_MEDIUM)
		ft_putendl_fd("Medium (O(n*sqrt(n)))", 2);
	else if (ctrl->mode == MODE_COMPLEX)
		ft_putendl_fd("Complex (O(n log n))", 2);
	else
	{
		if (ctrl->disorder >= 0.5)
			ft_putendl_fd("Adaptive (O(n log n))", 2);
		else if (ctrl->disorder >= 0.2)
			ft_putendl_fd("Adaptive (O(n*sqrt(n)))", 2);
		else
			ft_putendl_fd("Adaptive (O(n^2))", 2);
	}
}
void	print_bench_stats(t_control *ctrl)
{
	static char *op_names[11] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
		"rra", "rrb", "rrr"};
	int i;

	write(2, "Disorder: ", 11);

	print_disorder(ctrl->disorder, 2);

	write(2, "\n", 1);

	print_strategy(ctrl);

	write(2, "Total operations: ", 19);

	ft_putnbr_fd(ctrl->total_ops, 2);

	write(2, "\n", 1);

	i = 0;
	while (i < 11)
	{
		ft_putstr_fd(op_names[i], 2);
		write(2, ": ", 2);
		ft_putnbr_fd(ctrl->op_counts[i], 2);
		write(2, "\n", 1);
		i++;
	}
}