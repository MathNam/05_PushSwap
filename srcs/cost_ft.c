/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:49:08 by maaliber          #+#    #+#             */
/*   Updated: 2023/01/24 18:27:16 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long	rcost_idx_top(t_stack *stk, size_t idx)
{
	return ((long)idx_pos(stk, idx));
}

long	rrcost_idx_top(t_stack *stk, size_t idx)
{
	return ((long)(idx_pos(stk, idx) - stk_size(stk)));
}

long	cost_idx_top(t_stack *stk, size_t idx)
{
	size_t	size;
	size_t	pos_idx;

	size = stk_size(stk);
	pos_idx = idx_pos(stk, idx);
	if (pos_idx <= size - pos_idx)
		return ((long)pos_idx);
	else
		return ((long)(pos_idx - size));
}

long	set_cost(t_stack *dst_stk, t_stack *src_stk,
			t_stack *node_d, t_stack *node_s)
{
	long	r_cost_d;
	long	r_cost_s;
	long	rr_cost_d;
	long	rr_cost_s;

	node_d->cost = cost_idx_top(dst_stk, node_d->idx);
	node_s->cost = cost_idx_top(src_stk, node_s->idx);
	r_cost_d = rcost_idx_top(dst_stk, node_d->idx);
	r_cost_s = rcost_idx_top(src_stk, node_s->idx);
	rr_cost_d = rrcost_idx_top(dst_stk, node_d->idx);
	rr_cost_s = rrcost_idx_top(src_stk, node_s->idx);
	if (max_abs(r_cost_d, r_cost_s)
		< ft_abs(node_s->cost) + ft_abs(node_s->cost))
	{
		node_d->cost = r_cost_d;
		node_s->cost = r_cost_s;
	}
	if (max_abs(rr_cost_d, rr_cost_s)
		< ft_abs(node_s->cost) + ft_abs(node_s->cost))
	{
		node_d->cost = rr_cost_d;
		node_s->cost = rr_cost_s;
	}
	return (max_abs(node_d->cost, node_s->cost));
}
