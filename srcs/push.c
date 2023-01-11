/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:50:15 by maaliber          #+#    #+#             */
/*   Updated: 2023/01/10 19:51:03 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* push:
*	Pushes the top element of src stack to the top of dest stack.
*/

void	push(t_stack **stk_src, t_stack **stk_dst)
{
	t_stack *aft_top;
	
	if (!*stk_src)
		return ;
	aft_top = (*stk_src)->next;
	(*stk_src)->next = *stk_dst;
	*stk_dst = *stk_src;
	*stk_src = aft_top;
}

/* pa:
*	Pushes the top element of stack b to the top of stack a.
*	Prints "pa" to the standard output.
*/

void	pa(t_stack **a_stk, t_stack **b_stk)
{
	push(a_stk, b_stk);
	ft_printf("pa\n");
}

/* pb:
*	Pushes the top element of stack a to the top of stack b.
*	Prints "pb" to the standard output.
*/

void	pb(t_stack **a_stk, t_stack **b_stk)
{
	push(b_stk, a_stk);
	ft_printf("pa\n");
}
