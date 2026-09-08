/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serozdem <serozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 19:03:05 by serozdem          #+#    #+#             */
/*   Updated: 2026/09/07 15:21:21 by serozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
 #include "push_swap.h"

 void	free_stack(t_stack_info *stack)
{
	t_stack	*tmp;
	t_stack	*cur;

	if (!stack )
		return ;
	cur = stack->top;
	while (cur)
	{
		tmp = cur->next;
		free(cur);
		if (tmp == stack->top)
			tmp = NULL;
		cur = tmp;
	}
	free(stack);
}

void	free_all(t_control *ctrl)
{
	if (!ctrl)
		return ;
	if (ctrl->a)
		free_stack(ctrl->a);
	if (ctrl->b)
		free_stack(ctrl->b);
	free(ctrl);
}

<<<<<<< HEAD
t_control	*init_control(void)
{
	t_control	*ctrl;
	int			i;

	ctrl = malloc(sizeof(t_control));
	if (!ctrl)
		return (NULL);
	ctrl->a = malloc(sizeof(t_stack_info));
	if (!ctrl->a)
	{
		free(ctrl);
		return (NULL);
	}
	ctrl->b = malloc(sizeof(t_stack_info));
	if (!ctrl->b)
	{
		free(ctrl->a);
		free(ctrl);
		return (NULL);
	}
	ctrl->a->top = NULL;
	ctrl->a->size = 0;
	ctrl->b->top = NULL;
	ctrl->b->size = 0;
	ctrl->mode = MODE_ADAPTIVE;
	ctrl->bench = 0;
	ctrl->adaptive_checker = 0;
	ctrl->total_ops = 0;
	ctrl->disorder = 0.0;
	i = 0;
	while (i < 11)
	{
		ctrl->op_counts[i] = 0;
		i++;
	}
	return (ctrl);
=======
 int	process_arg(char *arg, t_control *ctrl)
{
	int	flag_res;

	flag_res = handle_flags(arg, ctrl);
	if (flag_res == 1)
		return (1);
	if (flag_res == -1)
		return (0);
	return (parse_number(arg, ctrl));
>>>>>>> dabf65fcf9eedcb8d1a61563e063498a8158667b
}

int	parse_args(int ac, char **av, t_control *ctrl)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!process_arg(av[i], ctrl))
			return (0);
		i++;
	}
	if (!ctrl->a || !ctrl->a->top)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_control	*ctrl;

	if (ac < 2)
		return (0);
	ctrl = init_control();
	if (!ctrl)
		return (1);
	if (!parse_args(ac, av, ctrl))
	{
		ft_error();
		free_all(ctrl);
		return (1);
	}
	if (!is_sorted(ctrl->a->top))
	{
		indexing(ctrl->a);
		execute_sort(ctrl);
	}
	free_all(ctrl);
	return (0);
}