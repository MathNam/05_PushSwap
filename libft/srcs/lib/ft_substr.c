/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:03:14 by maaliber          #+#    #+#             */
/*   Updated: 2023/01/05 16:11:37 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	int		size;

	if (!s)
		return (NULL);
	size = ft_strlen(s) - start;
	if (size > (int)len)
		size = len;
	if (size < 0)
		return (ft_strdup(""));
	subs = malloc(sizeof(char) * (size + 1));
	if (!subs)
		return (NULL);
	i = 0;
	s += start;
	while (i < len && *s)
		subs[i++] = *s++;
	return (subs[i] = '\0', subs);
}
