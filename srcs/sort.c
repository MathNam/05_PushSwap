/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:06:08 by maaliber          #+#    #+#             */
/*   Updated: 2023/01/11 15:23:34 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void short_sort(t_stack **a_stk, t_stack **b_stk)
{
	t_stack *max;
	
	while (stk_size(*a_stk) > 3)
		pa(a_stk, b_stk);
	max = get_max(*a_stk);
	while (!is_sorted(*a_stk))
	{
		if (*a_stk == max)
			ra(a_stk, b_stk);
		else if ((*a_stk)->next == max)
			rra(a_stk, b_stk);
		else
			sa(a_stk, b_stk);
	}
	if (stk_size(*b_stk) != 0)
		insertion_sort(a_stk, b_stk);
	while (stk_size(*b_stk) > 0)
		min_to_top(a_stk);
}

void sort(t_stack **a_stk, t_stack **b_stk)
{
	if (is_sorted(*a_stk))
		return ;
	if (stk_size(*a_stk) <= 5)
		short_sort(a_stk, b_stk);
	//else
	//	sort(a_stk, b_stk);
	return;
}
