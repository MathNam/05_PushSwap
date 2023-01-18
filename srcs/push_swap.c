/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:25:50 by maaliber          #+#    #+#             */
/*   Updated: 2023/01/18 17:18:57 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
