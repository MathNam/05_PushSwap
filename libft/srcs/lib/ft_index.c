/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:32:15 by maaliber          #+#    #+#             */
/*   Updated: 2023/01/05 16:11:37 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

ssize_t	ft_index(const char *s, int c)
{
	ssize_t			i;
	unsigned char	uc;

	if (!s)
		return (-1);
	uc = (unsigned char)c;
	i = 0;
	while (s[i] && s[i] != uc)
		i++;
	if (s[i] == uc)
		return (i);
	return (-1);
}
