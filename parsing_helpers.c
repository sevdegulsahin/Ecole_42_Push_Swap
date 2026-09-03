/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serozdem <serozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 17:21:43 by sevdsahi          #+#    #+#             */
/*   Updated: 2026/09/03 17:08:31 by serozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_flags(char *arg, t_control *ctrl)
{
	if (ft_strncmp(arg, "--", 2) != 0)
		return (0);
	if (ft_strncmp(arg, "--bench", 8) == 0)
	{
		ctrl->bench = 1;
		return (1);
	}
	if (ctrl->adaptive_checker != 0)
		return (-1);
	if (ft_strncmp(arg, "--adaptive", 11) == 0)
		ctrl->mode = 0;
	else if (ft_strncmp(arg, "--simple", 9) == 0)
		ctrl->mode = 1;
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		ctrl->mode = 2;
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		ctrl->mode = 3;
	else
		return (-1);
	ctrl->adaptive_checker = 1;
	return (1);
} 


 int	is_valid_arg(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_is_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parse_number(char *arg, t_control *ctrl)
{
	long	num;

	if (!is_valid_arg(arg))
		return (0);
	num = ft_atol(arg);
	if (num < -2147483648L || num > 2147483647L)
		return (0);
	if (!add_node_back(ctrl->a, (int)num))
		return (0);
	return (1);
}