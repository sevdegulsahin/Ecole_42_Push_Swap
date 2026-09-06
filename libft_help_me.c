/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_help_me.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevdsahi <sevdsahi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 18:31:17 by sevdsahi          #+#    #+#             */
/*   Updated: 2026/09/01 19:27:08 by sevdsahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_digit(int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
}

long	ft_atol(const char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_is_digit(str[i]))
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

void	ft_putnbr_fd(int n, int fd)
{
	char	buf[12];
	int		i;
	int		is_neg;

	is_neg = 0;
	i = 10;
	buf[11] = '\0';
	buf[10] = '0';
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
	{
		is_neg = 1;
		n = -n;
	}
	while (n > 0)
	{
		buf[i--] = '0' + (n % 10);
		n /= 10;
	}
	if (is_neg)
		buf[i--] = '-';
	write(fd, buf + i + 1, 10 - i);
}

static void	print_disorder(double d, int fd)
{
	int	int_part;
	int	dec_part;
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

void	print_bench_stats(t_control *ctrl)
{
	static char	*op_names[11] = {
		"sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"
	};
	static char	*mode_names[4] = {
		"Adaptive", "Simple", "Medium", "Complex"
	};
	static char	*complexity[4] = {
		"O(n^2)/O(n*sqrt(n))", "O(n^2)",
		"O(n*sqrt(n))", "O(n log n)"
	};
	int	i;

	write(2, "[bench] Disorder: ", 18);
	print_disorder(ctrl->disorder, 2);
	write(2, "\n", 1);
	write(2, "[bench] Strategy: ", 18);
	ft_putstr_fd(mode_names[ctrl->mode], 2);
	write(2, " (", 2);
	ft_putstr_fd(complexity[ctrl->mode], 2);
	write(2, ")\n", 2);
	write(2, "[bench] Total operations: ", 26);
	ft_putnbr_fd(ctrl->total_ops, 2);
	write(2, "\n", 1);
	i = 0;
	while (i < 11)
	{
		write(2, "[bench] ", 8);
		ft_putstr_fd(op_names[i], 2);
		write(2, ": ", 2);
		ft_putnbr_fd(ctrl->op_counts[i], 2);
		write(2, "\n", 1);
		i++;
	}
}
