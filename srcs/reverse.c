/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:50:49 by maaliber          #+#    #+#             */
/*   Updated: 2023/01/18 16:42:37 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* rev_rotate:
*	Brings the bottom element of a stack to the top.*/

void	rev_rotate(t_stack **stk)
{
	t_stack	*tail;
	t_stack	*pre_tail;

	if (!*stk || !(*stk)->next)
		return ;
	tail = stk_last(*stk);
	pre_tail = stk_lasttwo(*stk);
	tail->next = *stk;
	*stk = tail;
	pre_tail->next = NULL;
}

/* rra:
*	Brings the bottom element of stack a to the top.
*	Prints "rra" to the standard output.*/

void	rra(t_stack **a_stk)
{
	rev_rotate(a_stk);
	write(1, "rra\n", 4);
}

/* rrb:
*	Brings the bottom element of stack b to the top.
*	Prints "rrb" to the standard output.*/

void	rrb(t_stack **b_stk)
{
	rev_rotate(b_stk);
	write(1, "rrb\n", 4);
}

/* rrr:
*	Brings the bottom element of both stack a and stack be
*	to the top of their respective stacks.
*	Prints "rrr" to the standard output.*/

void	rrr(t_stack **a_stk, t_stack **b_stk)
{
	rev_rotate(a_stk);
	rev_rotate(b_stk);
	write(1, "rrr\n", 4);
}
