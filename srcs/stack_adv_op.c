/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_adv_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:50:23 by maaliber          #+#    #+#             */
/*   Updated: 2023/01/11 15:35:54 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	idx_to_top(t_stack **stk, size_t idx)
{
	size_t	size;
	size_t	pos_idx;
	
	size = stk_size(*stk);
	pos_idx = find_index_pos(*stk, (get_min(*stk))->idx);
	if (pos_idx < size - pos_idx)	
}