/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serozdem <serozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 13:58:59 by sevdsahi          #+#    #+#             */
/*   Updated: 2026/09/08 15:34:40 by serozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define MODE_ADAPTIVE 0
# define MODE_SIMPLE   1
# define MODE_MEDIUM   2
# define MODE_COMPLEX  3

# define OP_SA  0
# define OP_SB  1
# define OP_SS  2
# define OP_PA  3
# define OP_PB  4
# define OP_RA  5
# define OP_RB  6
# define OP_RR  7
# define OP_RRA 8
# define OP_RRB 9
# define OP_RRR 10

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_stack_info
{
	t_stack			*top;
	int				size;
}					t_stack_info;

typedef struct s_control
{
	t_stack_info	*a;
	t_stack_info	*b;
	int				mode;
	int				bench;
	int				adaptive_checker;
	int				total_ops;
	double			disorder;
	int				op_counts[11];
}					t_control;

t_control	*init_control(void);
void		free_stack(t_stack_info *stack);
void		free_all(t_control *ctrl);

void		push_nodes(t_stack **src, t_stack **dest);
void		swap_nodes(t_stack **stack);
void		rotate_nodes(t_stack **stack);
void		reverse_rotate_nodes(t_stack **stack);

void		sa(t_control *ctrl);
void		sb(t_control *ctrl);
void		ss(t_control *ctrl);
void		pa(t_control *ctrl);
void		pb(t_control *ctrl);
void		ra(t_control *ctrl);
void		rb(t_control *ctrl);
void		rr(t_control *ctrl);
void		rra(t_control *ctrl);
void		rrb(t_control *ctrl);
void		rrr(t_control *ctrl);

void		simple_sort(t_control *ctrl);
void		sort_three(t_control *ctrl);
void		sort_chunk(t_control *ctrl);
void		radix_sort(t_control *ctrl);
void		adaptive_sort(t_control *ctrl, double disorder);
void		execute_sort(t_control *ctrl);

int			is_sorted(t_stack *stack);
t_stack		*find_min(t_stack *stack);
t_stack		*find_max(t_stack *stack);
int			get_stack_size(t_stack *stack);
int has_value(t_stack *stack, int value);
int			get_position(t_stack *stack, t_stack *target);
void		indexing(t_stack_info *stack_a);
int			add_node_back(t_stack_info *stack, int value);

int			get_chunk_size(int total_size);
int			find_index_position(t_stack *b_top, int target_index);
void		push_chunk_to_b(t_control *ctrl, int min_bound, int max_bound);
void		push_back_to_a(t_control *ctrl);

int			get_max_bits(int size);
double		calculate_disorder(t_stack_info *a);
void	sort_small(t_control *ctrl);

int			ft_is_digit(int c);
size_t		ft_strlen(const char *s);
void		ft_error(void);
long		ft_atol(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		print_bench_stats(t_control *ctrl);
void ft_putendl_fd(char *s, int fd);

int			handle_flags(char *arg, t_control *ctrl);
int			is_valid_arg(char *str);
int			parse_number(char *arg, t_control *ctrl);
int			process_arg(char *arg, t_control *ctrl);
int	parse_args(int ac, char **av, t_control *ctrl);

char	*ft_substr(char const *s, unsigned int start, size_t len);
void	free_matrix(char **s);
int			word_count(const char *s, char c);
int			word_len(const char *s, char c);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);

#endif
