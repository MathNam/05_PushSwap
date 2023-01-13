/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:01:58 by maaliber          #+#    #+#             */
/*   Updated: 2023/01/13 16:03:13 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/libft.h"

/*Stack structure - Chained list with index and run number*/
typedef struct s_stack
{
	int				val;
	size_t			idx;
	int				run;
	struct s_stack	*next;
}	t_stack;

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

/*Stack manipulations functions*/
t_stack	*get_min(t_stack *stk);
t_stack	*get_max(t_stack *stk);
size_t	dest_idx(t_stack *dst_stk, size_t idx);
size_t	index_pos(t_stack *stk, size_t idx);
ssize_t	cost_idx_top(t_stack *stk, size_t idx);
void 	index_to_top(t_stack **stk, size_t idx, char id_stack);

/*Sorting functions*/
int		is_sorted(t_stack *stk);
int		is_near_sorted(t_stack *stk);
void	short_sort(t_stack **a_stk, t_stack **b_stk);
void	sort(t_stack **a_stk, t_stack **b_stk);

void err_msg(void);
t_stack	*get_input(int ac, char **av);
void	printf_stack(t_stack *a_stk, t_stack *b_stk);

#endif