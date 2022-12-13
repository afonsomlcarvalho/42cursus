/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:56:08 by amorais-          #+#    #+#             */
/*   Updated: 2022/12/13 17:02:08 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **a, t_stack **b, char c)
{
	t_stack	*temp;
	t_stack *temp1;

	if (!(*a))
		return ;
	if (!(*b))
	{
		*b = malloc(sizeof(t_stack));
		(*b)->number = (*a)->number;
		(*b)->next = NULL;
	}
	else
	{
		temp = malloc(sizeof(t_stack));
		temp->number = (*a)->number;
		temp->next = (*b);
		(*b) = temp;
	}
	temp1 = (*a);
	*a = (*a)->next;
	free(temp1);
	ft_printf("p%c\n", c);
}

void	swap(t_stack **a, char c)
{
	long int	swap;

	swap = (*a)->number;
	(*a)->number = (*a)->next->number;
	(*a)->next->number = swap;
	if (c)
		ft_printf("s%c\n", c);
}

void	rotate(t_stack **a, t_stack **b, char c)
{
	t_stack		*current;
	t_stack		*temp;

	if ((*a)->next)
	{
		temp = (*a);
		(*a) = (*a)->next;
		current = (*a);
		while (current->next)
			current = current->next;
		temp->next = NULL;
		current->next = temp;
	}
	if (c == 'r')
		rotate(b, a, 0);
	if (c)
		ft_printf("r%c\n", c);
}

void	reverse_rotate(t_stack **a, t_stack **b, char c)
{
	t_stack	*last;
	t_stack	*current;

	if ((*a)->next)
	{
		last = (*a);
		while (last->next)
			last = last->next;
		current = (*a);
		while (current->next->next)
			current = current->next;
		current->next = NULL;
		last->next = (*a);
		(*a) = last;
	}
	if (c == 'r')
		reverse_rotate(b, a, 0);
	if (c)
		ft_printf("rr%c\n", c);
}
