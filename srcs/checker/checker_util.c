/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:21:27 by maaliber          #+#    #+#             */
/*   Updated: 2023/02/08 11:14:02 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exit_err(t_stack **a_stk, t_stack **b_stk)
{
	stk_clear(a_stk);
	stk_clear(b_stk);
	err_msg();
	return (0);
}

int	push_swap_op(t_stack **a_stk, t_stack **b_stk, char *op)
{
	if (ft_strncmp(op, "pa", 2) == 0)
		push(b_stk, a_stk);
	else if (ft_strncmp(op, "pb", 2) == 0)
		push(a_stk, b_stk);
	else if (ft_strncmp(op, "sa", 2) == 0)
		swap(a_stk);
	else if (ft_strncmp(op, "sb", 2) == 0)
		swap(b_stk);
	else if (ft_strncmp(op, "ss", 2) == 0)
	{
		swap(a_stk);
		swap(b_stk);
	}
	else
		return (0);
	return (1);
}

int	rotate_op(t_stack **a_stk, t_stack **b_stk, char *op)
{
	if (ft_strncmp(op, "rra", 3) == 0)
		rev_rotate(a_stk);
	else if (ft_strncmp(op, "rrb", 3) == 0)
		rev_rotate(b_stk);
	else if (ft_strncmp(op, "rrr", 3) == 0)
	{
		rev_rotate(a_stk);
		rev_rotate(b_stk);
	}
	else if (ft_strncmp(op, "ra", 2) == 0)
		rotate(a_stk);
	else if (ft_strncmp(op, "rb", 2) == 0)
		rotate(b_stk);
	else if (ft_strncmp(op, "rr", 2) == 0)
	{
		rotate(a_stk);
		rotate(b_stk);
	}	
	else
		return (0);
	return (1);
}

int	exec_op(t_stack **a_stk, t_stack **b_stk, char *op)
{
	if (push_swap_op(a_stk, b_stk, op))
		return (1);
	if (rotate_op(a_stk, b_stk, op))
		return (1);
	return (0);
}
