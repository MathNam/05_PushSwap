/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:25:50 by maaliber          #+#    #+#             */
/*   Updated: 2023/04/15 16:42:49 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a_stk;
	t_stack	*b_stk;

	if (ac == 1)
		return (0);
	a_stk = get_input(ac, av);
	b_stk = NULL;
	if (!a_stk)
		return (err_msg(), 0);
	sort(&a_stk, &b_stk);
	stk_clear(&a_stk);
	stk_clear(&b_stk);
	return (0);
}
