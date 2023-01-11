/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:50:29 by maaliber          #+#    #+#             */
/*   Updated: 2023/01/10 19:51:27 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* rotate:
*	The top element of the stack is sent to the bottom.
*/

void	rotate(t_stack **stk)
{
	t_stack *top;
	t_stack *tail;
	
	if (!*stk || !(*stk)->next)
		return ;
	top = *stk;
	tail = stk_last(*stk);
	*stk = (*stk)->next;
	top->next = NULL;
	tail->next = top;
}

/* ra:
*	Sends the top element of stack a to the bottom.
*	Prints "ra" to the standard output.
*/

void	ra(t_stack **a_stk, t_stack **b_stk)
{
	(void)b_stk;
	rotate(a_stk);
	ft_printf("ra\n");
}

/* rb:
*	Sends the top element of stack b to the bottom.
*	Prints "rb" to the standard output.
*/

void	rb(t_stack **a_stk, t_stack **b_stk)
{
	(void)a_stk;
	rotate(b_stk);
	ft_printf("rb\n");
}

/* rr:
*	Sends the top element of both stack a and stack b to the bottom
*	of their respective stacks.
*	Prints "rr" to the standard output.
*/

void	rr(t_stack **a_stk, t_stack **b_stk)
{
	rotate(a_stk);
	rotate(b_stk);
	ft_printf("rr\n");
}