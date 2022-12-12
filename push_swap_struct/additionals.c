/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additionals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:55:17 by amorais-          #+#    #+#             */
/*   Updated: 2022/12/12 13:05:27 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printer(t_stack *a, t_stack *b)
{
	t_stack	*current;

	ft_printf("a: ");
	current = a;
	while (current)
	{
		ft_printf("%d ", current->number);
		current = current->next;
	}
	ft_printf("\nb: ");
	current = b;
	while (current)
	{
		ft_printf("%d ", current->number);
		current = current->next;
	}
	ft_printf("\n");
}

int	stack_size(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

t_stack	*stc_last(t_stack *a)
{
	t_stack	*last;

	last = a;
	while (last->next)
		last = last->next;
	return (last);
}

int	min_position(t_stack *a)
{
	int	min;
	int	i;
	int	m;

	i = 0;
	m = 0;
	min = a->number;
	while (a)
	{
		if (a->number < min)
		{
			min = a->number;
			m = i;
		}
		i++;
		a = a->next;
	}
	return (m);
}

int	max_position(t_stack *a)
{
	int	max;
	int	i;
	int	m;

	i = 0;
	m = 0;
	max = a->number;
	while (a)
	{
		if (a->number > max)
		{
			max = a->number;
			m = i;
		}
		i++;
		a = a->next;
	}
	return (m);
}
