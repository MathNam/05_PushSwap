/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:28:01 by maaliber          #+#    #+#             */
/*   Updated: 2023/01/25 14:48:56 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

size_t	*init_inv_array(t_stack *stk, size_t size)
{
	size_t	*arr;
	size_t	i;

	arr = malloc(2 * size * sizeof(size_t));
	if (!arr)
		return (NULL);
	i = 0;
	while (stk)
	{
		arr[i] = stk->idx;
		arr[i + size] = 1;
		stk = stk->next;
		i++;
	}
	return (arr);
}

void	assign_inv_run(t_stack *stk, size_t	*arr, size_t size)
{
	t_stack	*node;
	size_t	*cnt_arr;
	size_t	max;

	cnt_arr = arr + size;
	max = max_arr(cnt_arr, size);
	node = get_min(stk);
	while (size > 0)
	{
		if (*cnt_arr == max && *arr >= node->idx)
		{
			node = get_idx(stk, *arr);
			node->run = 0;
			max--;
		}
		size --;
		arr++;
		cnt_arr++;
	}
}

void	id_invariant(t_stack *stk)
{
	size_t	*arr;
	size_t	size;
	ssize_t	i;
	size_t	j;

	size = stk_size(stk);
	arr = init_inv_array(stk, size);
	if (!arr)
		return ;
	i = (ssize_t)size - 1;
	while (i >= 0)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[j] > arr[i] && arr[size + j] >= arr[size + i])
				arr[size + i] = arr[size + j] + 1;
			j++;
		}
		i--;
	}
	assign_inv_run(stk, arr, size);
	free(arr);
}

int	id_run(t_stack *stk, size_t run_size)
{
	t_stack	*stk_start;
	size_t	size;
	int		run_max;
	int		n;

	stk_start = stk;
	size = stk_size(stk);
	run_max = (stk_size(stk) / run_size);
	if (size % run_size)
		run_max++;
	n = 1;
	id_invariant(stk);
	while (n <= run_max)
	{
		while (stk)
		{
			if (stk->run == -1
				&& (stk->idx <= n * run_size))
				stk->run = n;
			stk = stk->next;
		}
		n++;
		stk = stk_start;
	}
	return (run_max);
}

void	push_run(t_stack **a_stk, t_stack **b_stk, int run_1, int run_2)
{
	ssize_t	size;

	size = (ssize_t)stk_size(*a_stk);
	while (size > 0)
	{
		if ((*a_stk)->run == run_1)
			pb(a_stk, b_stk);
		else if ((*a_stk)->run == run_2)
		{
			pb(a_stk, b_stk);
			if (size > 0 && (*a_stk)
				&& (*a_stk)->run != run_1 && (*a_stk)->run != run_2)
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
