/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_help_me_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serozdem <serozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 15:48:20 by serozdem          #+#    #+#             */
/*   Updated: 2026/09/08 18:40:10 by serozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

int	add_node_back(t_stack_info *stack, int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (0);
	new_node->value = value;
	new_node->index = 0;
	if (!stack->top)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		stack->top = new_node;
	}
	else
	{
		new_node->next = stack->top;
		new_node->prev = stack->top->prev;
		stack->top->prev->next = new_node;
		stack->top->prev = new_node;
	}
	stack->size++;
	return (1);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	char	*array;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	else if (len > s_len - start)
		len = s_len - start;
	array = (char *)(malloc(sizeof(char) * (len + 1)));
	if (!array)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		array[i] = s[start + i];
		i++;
	}
	array[i] = '\0';
	return (array);
}
