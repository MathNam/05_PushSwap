/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:53:19 by maaliber          #+#    #+#             */
/*   Updated: 2023/04/15 16:44:30 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	*op;
	t_stack	*a_stk;
	t_stack	*b_stk;

	if (ac == 1)
		return (0);
	a_stk = get_input(ac, av);
	b_stk = NULL;
	if (!a_stk)
		return (err_msg(), 0);
	op = get_next_line(0);
	while (op)
	{
		if (!exec_op(&a_stk, &b_stk, op))
			return (free(op), exit_err(&a_stk, &b_stk));
		free(op);
		op = get_next_line(0);
	}
	if (is_sorted(a_stk) && !b_stk)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	stk_clear(&a_stk);
	stk_clear(&a_stk);
	return (0);
}
