/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:56:10 by amorais-          #+#    #+#             */
/*   Updated: 2022/11/03 11:03:49 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*inter;

	while (*lst != NULL)
	{
		inter = (*lst)->next;
		ft_lstdelone(*lst, (*del));
		*lst = inter;
	}
	*lst = NULL;
}
