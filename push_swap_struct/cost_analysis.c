/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_analysis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:13:40 by amorais-          #+#    #+#             */
/*   Updated: 2022/12/13 10:47:05 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(t_stack *a)
{
	t_stack *min;

	min = a;
	while (a)
	{
		if (min->number > a->number)
			min = a;
		a = a->next;
	}
	return (min->number);
}

int	max(t_stack *a)
{
	t_stack *max;

	max = a;
	while (a)
	{
		if (max->number < a->number)
			max = a;
		a = a->next;
	}
	return (max->number);
}

int	position(t_stack *current, t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->number == current->number)
			return (i);
		i++;
		a = a->next;
	}
	return (-1);
}

int	position_in_other(int current, t_stack *a)
{
	int	i;

	i = 1;
	if (current < min(a) || current > max(a))
		return (min_position(a));
	if (current < a->number && current > stc_last(a)->number)
		return (0);
	while (!(current > a->number && current < a->next->number))
	{
		i++;
		a = a->next;
	}
	return (i);
}

int	cost(t_stack *current, t_stack *a, t_stack *b)
{
	int	i;
	int	l;
	int	cost;

	i = position(current, b);
	l = position_in_other(current->number, a);
	cost = 0;
	if (i == -1)
		return (-1);
	if (i <= stack_size(b) / 2 && l <= stack_size(a) / 2)
		while (i-- > 0 && l-- > 0)
			cost++;
	else if (i > stack_size(b) / 2 && l > stack_size(a) / 2)
		while (i++ < stack_size(b) && l++ <= stack_size(a))
			cost++;
	if (i <= stack_size(b) / 2)
		cost += i;
	else if (i < stack_size(b))
		cost += stack_size(b) - i;
	if (l <= stack_size(a) / 2)
		cost += l;
	else if (l < stack_size(a))
		cost += stack_size(a) - l;
	return (cost);
}
