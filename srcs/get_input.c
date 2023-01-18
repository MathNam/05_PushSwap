/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:59:21 by maaliber          #+#    #+#             */
/*   Updated: 2023/01/16 10:39:23 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* Check argument:
*	Check if the argument is composed only of digits and +- sign.
*	Check if the argument is an int within [INT_MIN32, INT_MAX32] range.*/

int	is_number(char *arg)
{
	int	s;

	s = 1;
	if (*arg == '+' || *arg == '-')
	{
		if (*arg == '-')
			s = 0;
		arg++;
	}
	while (*arg == '0')
		arg++;
	if (ft_strlen(arg) > 10)
		return (0);
	if ((s && ft_strlen(arg) == 10
			&& ft_strncmp(arg, "2147483647", 11) > 0)
		|| (!s && ft_strlen(arg) == 10
			&& ft_strncmp(arg, "2147483648", 11) > 0))
		return (0);
	while (*arg && ft_isdigit(*arg))
		arg++;
	if (*arg != '\0' && !ft_isdigit(*arg))
		return (0);
	return (1);
}

/* Retrieve data from arguments:
*	Retrieve arguments passed to the program as integer values and
*	store them into array of stack_size * 2 for indexing purposes, 
*	index part is initialized at 0.
*	Check if each argument is an number within [INT_MIN32, INT_MAX32] range.*/

int	*init_data(char **av, size_t size)
{
	int		*data;
	size_t	i;

	data = ft_calloc(2 * size, sizeof(int));
	if (!data)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!is_number(av[i + 1]))
			return (NULL);
		data[i] = ft_atoi(av[i + 1]);
		i++;
	}
	return (data);
}

/* Indexing:
*	Assign a position to each value in stack a. This is a convenient way to
*	order the stack because position can be checked and compared instead of 
*	actual values, which may or may not be adjacent to each other.
*		ex. values:		-3	 0	 9	 2
*		indexes:		[0]	[1]	[3]	[2]
*	The positions are assigned from highest (stack_size - 1) to lowest (0).*/

int	indexing(int *data, size_t size)
{
	size_t	idx;
	size_t	i;

	idx = 0;
	while (idx < size)
	{
		i = 0;
		while (i < size)
		{
			if (i != idx)
			{
				if (data[idx] > data[i])
					data[idx + size]++;
				else if (data[idx] == data[i])
					return (0);
			}
			i++;
		}
		idx++;
	}
	return (1);
}

/* Stack initialization:
*	Creating the entire stack as linked list from data retrieved from the 
*	arguments, [val] is the int value of the argument, [idx] is th position in 
*	the final ordered list of the element, [run] is initialized at -1.*/

t_stack	*init_stack(int *data, size_t size)
{
	t_stack	*stack;
	t_stack	*node;
	size_t	i;

	i = 0;
	stack = NULL;
	while (i < size)
	{
		node = stk_new(data[i], data[i + size]);
		if (node == NULL)
			return (stk_clear(&stack), NULL);
		stk_add_back(&stack, node);
		i++;
	}
	return (stack);
}

t_stack	*get_input(int ac, char **av)
{
	t_stack	*stack;
	int		*data;
	size_t	size;

	if (ac < 2)
		return (err_msg(), NULL);
	size = ac - 1;
	data = init_data(av, size);
	if (!data)
		return (err_msg(), NULL);
	if (!indexing(data, size))
		return (free(data), err_msg(), NULL);
	stack = init_stack(data, size);
	return (free(data), stack);
}
