/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_adv_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:50:23 by maaliber          #+#    #+#             */
/*   Updated: 2023/01/13 19:07:55 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

size_t	dest_idx(t_stack *dst_stk, size_t idx)
{
	t_stack	*min;
	t_stack	*max;
	t_stack	*node;

	min = get_min(dst_stk);
	max = get_max(dst_stk);
	if (idx < min->idx)
		return (min->idx);
	if (idx > max->idx && max->next)
		return (max->next->idx);
	if ((idx > max->idx && max->next)
		|| (idx < dst_stk->idx && idx > stk_last(dst_stk)->idx))
		return (dst_stk->idx);
	node = dst_stk;
	while (node->next)
	{
		if (idx > node->idx && idx < node->next->idx)
			return (node->next->idx);
		node = node->next;
	}
	return (dst_stk->idx);
}

ssize_t	cost_idx_top(t_stack *stk, size_t idx)
{
	size_t	size;
	size_t	pos_idx;

	size = stk_size(stk);
	pos_idx = index_pos(stk, idx);
	if (pos_idx <= size - pos_idx)
		return ((ssize_t)pos_idx);
	else
		return ((ssize_t)(pos_idx - size));
}

void	index_to_top(t_stack **stk, size_t idx, char id_stack)
{
	ssize_t		cost;
	static void	(*op[4])(t_stack **)
		= {ra, rra, rb, rrb};
	size_t		ft_id;

	cost = cost_idx_top(*stk, idx);
	ft_id = 0;
	if (cost < 0)
	{
		ft_id++;
		cost *= -1;
	}
	if (id_stack == 'B')
		ft_id *= 2;
	while (cost-- > 0)
		op[ft_id](stk);
}
