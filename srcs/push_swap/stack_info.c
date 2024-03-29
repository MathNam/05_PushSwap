/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:48:19 by maaliber          #+#    #+#             */
/*   Updated: 2023/02/07 14:32:32 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stk)
{
	while (stk && stk->next)
	{
		if (stk->idx > stk->next->idx)
			return (0);
		stk = stk->next;
	}
	return (1);
}

t_stack	*get_min(t_stack *stk)
{
	t_stack	*min;

	min = stk;
	while (stk)
	{
		if (stk->idx < min->idx)
			min = stk;
		stk = stk->next;
	}
	return (min);
}

t_stack	*get_max(t_stack *stk)
{
	t_stack	*max;

	max = stk;
	while (stk)
	{
		if (stk->idx > max->idx)
			max = stk;
		stk = stk->next;
	}
	return (max);
}

t_stack	*get_idx(t_stack *stk, size_t idx)
{
	while (stk)
	{
		if (stk->idx == idx)
			return (stk);
		stk = stk->next;
	}
	return (NULL);
}

size_t	idx_pos(t_stack *stk, size_t idx)
{
	size_t	pos;

	pos = 0;
	while (stk)
	{
		if (stk->idx == idx)
			return (pos);
		pos++;
		stk = stk->next;
	}
	return (pos);
}
