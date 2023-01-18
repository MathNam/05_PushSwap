/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_ft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:15:15 by maaliber          #+#    #+#             */
/*   Updated: 2023/01/18 15:15:01 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	max_abs(int m, int n)
{
	if (n < 0)
		n *= -1;
	if (m < 0)
		m *= -1;
	if (m > n)
		return (m);
	return (n);
}

size_t	max_arr(size_t *arr, size_t size)
{
	size_t	max;

	if (!arr)
		return (0);
	max = 0;
	while (size > 0)
	{
		if (max < *arr)
			max = *arr;
		arr++;
		size--;
	}
	return (max);
}

void	err_msg(void)
{
	ft_printf("Error\n");
}

void	printf_stack(t_stack *a_stk, t_stack *b_stk)
{
	ft_printf("------------------------\n");
	ft_printf("%11s||%-11s\n", "- A-Stack -", "- B-Stack -");
	while (a_stk && b_stk)
	{
		ft_printf("[%2d]%11d||%-11d\n", a_stk->run, a_stk->idx, b_stk->idx);
		a_stk = a_stk->next;
		b_stk = b_stk->next;
	}
	while (a_stk)
	{
		ft_printf("[%2d]%11d||%-11s\n", a_stk->run, a_stk->idx, "");
		a_stk = a_stk->next;
	}
	while (b_stk)
	{
		ft_printf("[%2d]%11s||%-11d\n", 0, "", b_stk->idx);
		b_stk = b_stk->next;
	}
	ft_printf("------------------------\n");
	return ;
}
