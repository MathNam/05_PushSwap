/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:01:58 by maaliber          #+#    #+#             */
/*   Updated: 2023/02/07 16:30:22 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

/*Stack structure - Chained list with index and run number*/
typedef struct s_stack
{
	int				val;
	size_t			idx;
	int				run;
	int				cost;
	struct s_stack	*next;
}	t_stack;

/*Utility functions*/
int		ft_abs(int n);
int		max_abs(int m, int n);
size_t	max_arr(size_t *arr, size_t size);
void	err_msg(void);
void	printf_stack(t_stack *a_stk, t_stack *b_stk);

/*Stack core functions - Basic fonctions for stack creation & deletion*/
int		stk_size(t_stack *stk);
t_stack	*stk_new(int value, int index);
t_stack	*stk_last(t_stack *stk);
t_stack	*stk_lasttwo(t_stack *stk);
void	stk_add_back(t_stack **stk, t_stack *snew);
void	stk_delone(t_stack *stk);
void	stk_clear(t_stack **stk);

/*Push Swap operations - Push, Swap, Rotate, Reverse*/
void	push(t_stack **stk_src, t_stack **stk_dst);
void	pa(t_stack **a_stk, t_stack **b_stk);
void	pb(t_stack **a_stk, t_stack **b_stk);
void	swap(t_stack **stk);
void	sa(t_stack **a_stk);
void	sb(t_stack **b_stk);
void	ss(t_stack **a_stk, t_stack **b_stk);
void	rotate(t_stack **stk);
void	ra(t_stack **a_stk);
void	rb(t_stack **b_stk);
void	rr(t_stack **a_stk, t_stack **b_stk);
void	rev_rotate(t_stack **stk);
void	rra(t_stack **a_stk);
void	rrb(t_stack **b_stk);
void	rrr(t_stack **a_stk, t_stack **b_stk);

/*Cost functions - Determine cost for operations*/
long	rcost(t_stack *stk, size_t idx);
long	rrcost(t_stack *stk, size_t idx);
long	cost_idx_top(t_stack *stk, size_t idx);
long	set_cost(t_stack *dst_stk, t_stack *src_stk,
			t_stack *node_d, t_stack *node_s);

/*Cost operations - Rotate, Reverse*/
void	cost_rs(t_stack **stk, int *cost, char id_stack);
void	cost_rrs(t_stack **stk, int *cost, char id_stack);
void	cost_rr(t_stack **a_stk, t_stack **b_stk, int *cost_a, int *cost_b);
void	cost_rrr(t_stack **a_stk, t_stack **b_stk, int *cost_a, int *cost_b);

/*Stack manipulations functions*/
t_stack	*get_min(t_stack *stk);
t_stack	*get_max(t_stack *stk);
t_stack	*get_idx(t_stack *stk, size_t idx);
t_stack	*search_dst(t_stack *dst_stk, size_t idx_src);
size_t	idx_pos(t_stack *stk, size_t idx);
ssize_t	cost_idx_top(t_stack *stk, size_t idx);
void	idx_top(t_stack **stk, size_t idx, char id_stack);
int		optimal_idx_top(t_stack **a_stk, t_stack **b_stk, int run_id);

/*Run identification functions*/
size_t	*init_inv_array(t_stack *stk, size_t size);
void	assign_inv_run(t_stack *stk, size_t	*arr, size_t size);
void	id_invariant(t_stack *stk);
int		id_run(t_stack *stk, size_t run_size);
void	push_run(t_stack **a_stk, t_stack **b_stk, int run_1, int run_2);

/*Sorting functions*/
int		is_sorted(t_stack *stk);
int		is_near_sorted(t_stack *stk);
void	insertion_sort(t_stack **a_stk, t_stack **b_stk);
void	cost_sort(t_stack **a_stk, t_stack **b_stk, int max_run);
void	short_sort(t_stack **a_stk, t_stack **b_stk);
void	sort(t_stack **a_stk, t_stack **b_stk);

/*Input processing functions*/
int		is_number(char *arg);
int		*init_data(char **av, size_t size);
int		indexing(int *data, size_t size);
t_stack	*init_stack(int *data, size_t size);
t_stack	*get_input(int ac, char **av);

/*Checker functions*/
int		exit_err(t_stack **a_stk, t_stack **b_stk);
int		push_swap_op(t_stack **a_stk, t_stack **b_stk, char *op);
int		rotate_op(t_stack **a_stk, t_stack **b_stk, char *op);
int		exec_op(t_stack **a_stk, t_stack **b_stk, char *op);

#endif