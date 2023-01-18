/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:20:12 by maaliber          #+#    #+#             */
/*   Updated: 2023/01/18 17:49:46 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	cost_rs(t_stack **stk, int *cost, char id_stack)
{
	if (id_stack == 'A')
	{
		ra(stk);
		*cost -= 1;
	}
	if (id_stack == 'B')
	{
		rb(stk);
		*cost -= 1;
	}
}

void	cost_rrs(t_stack **stk, int *cost, char id_stack)
{
	if (id_stack == 'A')
	{
		rra(stk);
		*cost += 1;
	}
	if (id_stack == 'B')
	{
		rrb(stk);
		*cost += 1;
	}
}

void	cost_rr(t_stack **a_stk, t_stack **b_stk, int *cost_a, int *cost_b)
{
	rr(a_stk, b_stk);
	*cost_a -= 1;
	*cost_b -= 1;
}

void	cost_rrr(t_stack **a_stk, t_stack **b_stk, int *cost_a, int *cost_b)
{
	rrr(a_stk, b_stk);
	*cost_a += 1;
	*cost_b += 1;
}
