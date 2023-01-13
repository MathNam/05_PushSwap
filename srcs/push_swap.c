/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:25:50 by maaliber          #+#    #+#             */
/*   Updated: 2023/01/13 19:03:41 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	printf_stack(t_stack *a_stk, t_stack *b_stk)
{
	ft_printf("------------------------\n");
	ft_printf("%11s||%-11s\n", "- A-Stack -", "- B-Stack -");
	while (a_stk && b_stk)
	{
		ft_printf("%11d||%-11d\n", a_stk->idx, b_stk->idx);
		a_stk = a_stk->next;
		b_stk = b_stk->next;
	}
	while (a_stk)
	{
		ft_printf("%11d||%-11s\n", a_stk->idx, "");
		a_stk = a_stk->next;
	}
	while (b_stk)
	{
		ft_printf("%11s||%-11d\n", "", b_stk->idx);
		b_stk = b_stk->next;
	}
	ft_printf("------------------------\n");
	return ;
}

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;

	a_stack = get_input(ac, av);
	b_stack = NULL;
	if (!a_stack)
		return (0);
	sort(&a_stack, &b_stack);
	stk_clear(&a_stack);
	stk_clear(&b_stack);
	return (0);
}
