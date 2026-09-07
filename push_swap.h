/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serozdem <serozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 13:58:59 by sevdsahi          #+#    #+#             */
/*   Updated: 2026/09/03 21:28:08 by serozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

# define MODE_ADAPTIVE 0
# define MODE_SIMPLE   1
# define MODE_MEDIUM   2
# define MODE_COMPLEX  3

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
}					t_control;


void	adaptive_sort(t_control *ctrl, double disorder);
void	execute_sort(t_control *ctrl);

double	calculate_disorder(t_stack_info *a);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**free_split(char **s, int i);
int	word_count(const char *s, char c);

int	word_len(const char *s, char c);
char	**ft_split(char const *s, char c);

int	is_sorted(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);
int	get_stack_size(t_stack *stack);
int	has_duplicate(t_stack *stack);
int	ft_is_digit(int c);
size_t	ft_strlen(const char *s);
void	ft_error(void);
long    ft_atol(const char *str);
 int	get_chunk_size(int total_size);
 
 int	find_index_position(t_stack *b_top, int target_index);
 void	push_chunk_to_b(t_control *ctrl, int min_bound, int max_bound);
 void	push_back_to_a(t_control *ctrl);
 void	sort_chunk(t_control *ctrl);
 int	handle_flags(char *arg, t_control *ctrl);
  int	is_valid_arg(char *str);
  int	parse_number(char *arg, t_control *ctrl);
  
void	push_nodes(t_stack **src, t_stack **dest);
void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **a, t_stack **b, int print);
 void	free_stack(t_stack_info *stack);
void	free_all(t_control *ctrl);

 int	process_arg(char *arg, t_control *ctrl);
 int	parse_args(int ac, char **av, t_control *ctrl);
 int	get_max_bits(int size);
 void	radix_sort(t_control *ctrl);
 void reverse_rotate_nodes(t_stack **stack);
void rra(t_stack **a, int print);
void rrb(t_stack **b, int print);
void rrr(t_stack **a, t_stack **b, int print);
void rotate_nodes(t_stack **stack);
void ra(t_stack **a, int print);
void rb(t_stack **b, int print);
void rr(t_stack **a, t_stack **b, int print);
void sort_three(t_stack **stack_a);
void simple_sort(t_stack **stack_a, t_stack **stack_b);
int	get_position(t_stack *stack, t_stack *target);
void	indexing(t_stack_info *stack_a);
void	swap_nodes(t_stack **stack); 

void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b, int print);


#endif