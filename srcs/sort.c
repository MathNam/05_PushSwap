/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:06:08 by maaliber          #+#    #+#             */
/*   Updated: 2023/01/13 19:08:06 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*void	id_invariant(t_stack *stk)
{
	size_t	*idx_arr;
	size_t	size;
	size_t	i;

	size = stk_size(stk);
	idx_arr = ft_setalloc(4 * size * sizeof(size_t), 1, 0);
	if (!idx_arr)
		return ;
	i = 0;
	while (stk)
	{
		idx_arr[i] = stk->idx;
		idx_arr[i + size] = stk->idx;
		stk = stk->next;
	}
	free(idx_arr);
}*/

int	id_run(t_stack *stk, size_t run_size)
{
	int	n_run;

	n_run = 0;
	//id_invariant(stk);
	while (stk)
	{
		if (stk->run != 0)
			stk->run = stk->idx / run_size + 1;
		if (stk->run > n_run)
			n_run = stk->run;
		stk = stk->next;
	}
	return (n_run);
}

void	push_run(t_stack **a_stk, t_stack **b_stk, int id_run, size_t run_size)
{
	size_t	idx_median;
	size_t	size;

	size = stk_size(*a_stk);
	idx_median = run_size * (id_run - 1) + run_size / 2;
	while (size > 0)
	{
		if ((*a_stk)->run == id_run && (*a_stk)->idx > idx_median)
			pb(a_stk, b_stk);
		else if ((*a_stk)->run == id_run && (*a_stk)->idx <= idx_median)
		{
			pb(a_stk, b_stk);
			if (*a_stk && (*a_stk)->run != id_run)
			{
				rr(a_stk, b_stk);
				size--;
			}
			else
				rb(b_stk);
		}
		else
			ra(a_stk);
		size--;
	}
}

void	insertion_sort(t_stack **a_stk, t_stack **b_stk)
{
	while (*b_stk)
	{
		if (!(*a_stk))
			pa(a_stk, b_stk);
		index_to_top(a_stk, dest_idx(*a_stk, (*b_stk)->idx), 'A');
		pa(a_stk, b_stk);
	}
	index_to_top(a_stk, 0, 'A');
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
	size_t	run_size;
	int		n_run;

	run_size = 64;
	if (is_sorted(*a_stk))
		return ;
	n_run = id_run(*a_stk, run_size);
	while (n_run > 0)
	{
		push_run(a_stk, b_stk, n_run, run_size);
		n_run--;
	}
	insertion_sort(a_stk, b_stk);
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
