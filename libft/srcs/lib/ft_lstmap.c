/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:08:44 by maaliber          #+#    #+#             */
/*   Updated: 2023/01/05 16:11:37 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*nlast;

	if (!lst || !f)
		return (NULL);
	newlst = ft_lstnew((*f)(lst->content));
	nlast = newlst;
	if (!newlst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		nlast->next = ft_lstnew((*f)(lst->content));
		if (!nlast->next)
			return (ft_lstclear(&newlst, (*del)), NULL);
		nlast = nlast->next;
	}
	return (newlst);
}
