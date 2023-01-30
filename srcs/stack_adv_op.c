/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_adv_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:50:23 by maaliber          #+#    #+#             */
/*   Updated: 2023/01/30 15:45:58 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*search_dst(t_stack *dst_stk, size_t idx_src)
{
	t_stack	*min;
	t_stack	*max;
	t_stack	*node;

	min = get_min(dst_stk);
	max = get_max(dst_stk);
	if (idx_src < min->idx || idx_src > max->idx)
		return (min);
	node = dst_stk;
	while (node->next)
	{
		if (idx_src > node->idx && idx_src < node->next->idx)
			return (node->next);
		node = node->next;
	}
	return (dst_stk);
}

void	idx_top(t_stack **stk, size_t idx, char id_stack)
{
	ssize_t		cost;
	static void	(*op[4])(t_stack **)
		= {ra, rra, rb, rrb};
	size_t		ft_id;

	if (!(*stk))
		return ;
	cost = cost_idx_top(*stk, idx);
	ft_id = 0;
	if (id_stack == 'B')
		ft_id += 2;
	if (cost < 0)
	{
		ft_id++;
		cost *= -1;
	}
	while (cost-- > 0)
		op[ft_id](stk);
}

t_stack	*optimal_node(t_stack *dst_stk, t_stack *src_stk, int run_id)
{
	t_stack	*op_node;
	t_stack	*node;
	int		min_cost;
	int		cost;

	op_node = NULL;
	node = src_stk;
	min_cost = INT32_MAX;
	while (node)
	{
		if (node->run == run_id)
		{
			cost = set_cost(dst_stk, src_stk,
					search_dst(dst_stk, node->idx), node);
			if (cost < min_cost)
			{	
				min_cost = cost;
				op_node = node;
			}
		}
		node = node->next;
	}
	if (op_node)
		set_cost(dst_stk, src_stk, search_dst(dst_stk, op_node->idx), op_node);
	return (op_node);
}

int	optimal_idx_top(t_stack **a_stk, t_stack **b_stk, int run_id)
{
	t_stack	*node_b;
	t_stack	*node_a;

	node_b = optimal_node(*a_stk, *b_stk, run_id);
	if (!node_b)
		return (0);
	node_a = search_dst(*a_stk, node_b->idx);
	while (node_a->cost != 0 || node_b->cost != 0)
	{
		if (node_a->cost > 0 && node_b->cost > 0)
			cost_rr(a_stk, b_stk, &(node_a->cost), &(node_b->cost));
		else if (node_a->cost > 0)
			cost_rs(a_stk, &(node_a->cost), 'A');
		else if (node_b->cost > 0)
			cost_rs(b_stk, &(node_b->cost), 'B');
		else if (node_a->cost < 0 && node_b->cost < 0)
			cost_rrr(a_stk, b_stk, &(node_a->cost), &(node_b->cost));
		else if (node_a->cost < 0)
			cost_rrs(a_stk, &(node_a->cost), 'A');
		else if (node_b->cost < 0)
			cost_rrs(b_stk, &(node_b->cost), 'B');
	}
	return (1);
}
