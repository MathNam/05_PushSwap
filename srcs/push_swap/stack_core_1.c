/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_core_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:54:50 by maaliber          #+#    #+#             */
/*   Updated: 2023/02/07 14:32:32 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stk_size(t_stack *stk)
{
	int	size;

	size = 0;
	while (stk)
	{
		stk = stk->next;
		size++;
	}
	return (size);
}

t_stack	*stk_new(int val, int idx)
{
	t_stack	*stk;

	stk = malloc(sizeof(t_stack));
	if (!stk)
		return (NULL);
	stk->val = val;
	stk->idx = idx;
	stk->run = -1;
	stk->cost = 0;
	stk->next = NULL;
	return (stk);
}

t_stack	*stk_last(t_stack *stk)
{
	if (!stk)
		return (NULL);
	while (stk->next)
		stk = stk->next;
	return (stk);
}

t_stack	*stk_lasttwo(t_stack *stk)
{
	if (!stk || !(stk->next))
		return (NULL);
	while (stk->next->next)
		stk = stk->next;
	return (stk);
}
