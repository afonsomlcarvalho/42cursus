/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:44:15 by amorais-          #+#    #+#             */
/*   Updated: 2022/11/03 15:46:38 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*inter;

	new = NULL;
	while (lst != NULL)
	{
		inter = ft_lstnew((*f)(lst->content));
		if (!inter)
		{
			ft_lstclear(&new, (*del));
			return (new);
		}
		lst = lst->next;
		ft_lstadd_back(&new, inter);
	}
	return (new);
}
