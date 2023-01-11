/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_core_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:54:50 by maaliber          #+#    #+#             */
/*   Updated: 2023/01/11 14:47:09 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	stk_add_back(t_stack **stk, t_stack *new)
{
	t_stack	*last;

	if (!stk || !new)
		return ;
	if (!(*stk))
	{
		(*stk) = new;
		return ;
	}
	last = stk_last(*stk);
	last->next = new;
}

void	stk_delone(t_stack *stk)
{
	if (!stk)
		return ;
	stk->val = 0;
	stk->idx = 0;
	free(stk);
	stk = NULL;
}

void	stk_clear(t_stack **stk)
{
	t_stack	*next;

	if (!stk)
		return ;
	while (*stk)
	{
		next = (*stk)->next;
		stk_delone(*stk);
		*stk = next;
	}
}
