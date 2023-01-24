/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:06:08 by maaliber          #+#    #+#             */
/*   Updated: 2023/01/19 16:28:08 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	insertion_sort(t_stack **a_stk, t_stack **b_stk)
{
	while (*b_stk)
	{
		if (!(*a_stk))
			pa(a_stk, b_stk);
		idx_top(a_stk, search_dst(*a_stk, (*b_stk)->idx)->idx, 'A');
		pa(a_stk, b_stk);
	}
	idx_top(a_stk, 0, 'A');
}

void	cost_sort(t_stack **a_stk, t_stack **b_stk, int max_run)
{
	int	run_id;

	run_id = 1;
	while (run_id <= max_run)
	{
		if (!(*a_stk))
			pa(a_stk, b_stk);
		if (!optimal_idx_top(a_stk, b_stk, run_id))
			run_id++;
		else
			pa(a_stk, b_stk);
	}
	idx_top(a_stk, 0, 'A');
}

void	short_sort(t_stack **a_stk, t_stack **b_stk)
{
	t_stack	*max;

	while (stk_size(*a_stk) > 3)
		pb(a_stk, b_stk);
	max = get_max(*a_stk);
	while (!is_sorted(*a_stk))
	{
		if (*a_stk == max)
			ra(a_stk);
		else if ((*a_stk)->next == max)
			rra(a_stk);
		else
			sa(a_stk);
	}
	if (stk_size(*b_stk) != 0)
		insertion_sort(a_stk, b_stk);
}

void	long_sort(t_stack **a_stk, t_stack **b_stk)
{
	static size_t	run_size[5] = {16, 32, 64, 128, 256};
	int				max_run;
	int				run_1;
	int				run_2;

	if (is_sorted(*a_stk))
		return ;
	max_run = id_run(*a_stk, run_size[2]);
	run_1 = max_run / 2;
	run_2 = max_run / 2 + 1;
	while (run_1 > 0 && run_2 <= max_run)
	{
		push_run(a_stk, b_stk, run_1, run_2);
		run_1--;
		run_2++;
	}
	if (max_run % 2)
		push_run(a_stk, b_stk, run_2, -1);
	cost_sort(a_stk, b_stk, max_run);
	return ;
}

void	sort(t_stack **a_stk, t_stack **b_stk)
{
	if (is_sorted(*a_stk))
		return ;
	if (stk_size(*a_stk) <= 5)
		short_sort(a_stk, b_stk);
	else
		long_sort(a_stk, b_stk);
	return ;
}
