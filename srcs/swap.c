/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:50:07 by maaliber          #+#    #+#             */
/*   Updated: 2023/01/16 11:00:06 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* swap:
*	Swaps the top 2 elements of a stack.
*	Does nothing if there is only one or no elements.*/

void	swap(t_stack **stk)
{
	t_stack	*top;

	if (!*stk || !(*stk)->next)
		return ;
	top = *stk;
	*stk = (*stk)->next;
	top->next = (*stk)->next;
	(*stk)->next = top;
}

/* sa:
*	Swaps the top 2 elements of stack a.
*	Prints "sa" to the standard output.*/

void	sa(t_stack **a_stk)
{
	swap(a_stk);
	write(1, "sa\n", 3);
}

/* sb:
*	Swaps the top 2 elements of stack b.
*	Prints "sb" to the standard output.*/

void	sb(t_stack **b_stk)
{
	swap(b_stk);
	write(1, "sb\n", 3);
}

/* do_ss:
*	Swaps the top 2 elements of stack a and the top 2 elements
*	of stack b.
*	Prints "ss" to the standard output.*/

void	ss(t_stack **a_stk, t_stack **b_stk)
{
	swap(a_stk);
	swap(b_stk);
	write(1, "ss\n", 3);
}
