/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:49:08 by maaliber          #+#    #+#             */
/*   Updated: 2023/01/30 15:57:30 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long	rcost(t_stack *stk, size_t idx)
{
	return ((long)idx_pos(stk, idx));
}

long	rrcost(t_stack *stk, size_t idx)
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
	long	rc_d;
	long	rc_s;
	long	rrc_d;
	long	rrc_s;

	node_d->cost = cost_idx_top(dst_stk, node_d->idx);
	node_s->cost = cost_idx_top(src_stk, node_s->idx);
	if (node_d->cost * node_s->cost >= 0)
		return (max_abs(node_d->cost, node_s->cost));
	rc_d = rcost(dst_stk, node_d->idx);
	rc_s = rcost(src_stk, node_s->idx);
	rrc_d = rrcost(dst_stk, node_d->idx);
	rrc_s = rrcost(src_stk, node_s->idx);
	if (max_abs(rc_d, rc_s) < ft_abs(node_d->cost) + ft_abs(node_s->cost))
	{
		node_d->cost = rc_d;
		node_s->cost = rc_s;
	}
	if (max_abs(rrc_d, rrc_s) < ft_abs(node_d->cost) + ft_abs(node_s->cost))
	{
		node_d->cost = rrc_d;
		node_s->cost = rrc_s;
	}
	return (max_abs(node_d->cost, node_s->cost));
}
