/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:25:50 by maaliber          #+#    #+#             */
/*   Updated: 2023/01/24 15:35:06 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a_stk;
	t_stack	*b_stk;

	a_stk = get_input(ac, av);
	b_stk = NULL;
	if (!a_stk)
		return (err_msg(), 0);
	sort(&a_stk, &b_stk);
	stk_clear(&a_stk);
	stk_clear(&b_stk);
	return (0);
}
