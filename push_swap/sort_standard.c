/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_standard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:56:26 by amorais-          #+#    #+#             */
/*   Updated: 2022/12/15 15:33:16 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_cost(t_stack *current, t_stack **a, t_stack **b)
{
	int	i;
	int	l;

	i = position(current, *b);
	l = position_in_other(current->number, *a);
	if (i <= stack_size(*b) / 2 && l <= stack_size(*a) / 2 && i > 0 && l > 0)
		while (l > 0 && i > 0 && i-- > 0 && l-- > 0)
			rotate(a, b, 'r');
	else if (i > stack_size(*b) / 2 && l > stack_size(*a) / 2 && i != -1)
		while (i < stack_size(*b) && l < stack_size(*a) && i++ < \
		stack_size(*b) && l++ < stack_size(*a))
			reverse_rotate(a, b, 'r');
	if (i <= stack_size(*b) / 2 && i != -1)
		while (i-- > 0)
			rotate(b, a, 'b');
	else if (i < stack_size(*b) && i != -1)
		while (i++ < stack_size(*b))
			reverse_rotate(b, a, 'b');
	if (l <= stack_size(*a) / 2)
		while (l-- > 0)
			rotate(a, b, 'a');
	else if (l < stack_size(*a))
		while (l++ < stack_size(*a))
			reverse_rotate(a, b, 'a');
	push(b, a, 'a');
}

t_stack	*min_cost_finder(t_stack *a, t_stack *b)
{
	t_stack	*min_cost;
	t_stack	*current;

	min_cost = b;
	current = b;
	while (current)
	{
		if (cost(min_cost, a, b) > cost(current, a, b))
			min_cost = current;
		current = current->next;
	}
	return (min_cost);
}

int		diff_sorted(t_stack *a)
{
	long int	first;

	if (sorted(a))
		return (1);
	first = a->number;
	while (a->number < a->next->number)
		a = a->next;
	a = a->next;
	while (a->next)
	{
		if (a->number > a->next->number)
			return (0);
		a = a->next;
	}
	return (first > a->number);
}

void	pusher(t_stack **a, t_stack **b)
{
	while (stack_size(*a) > 3 && !diff_sorted(*a))
		push(a, b, 'b');
	if (!diff_sorted(*a))
		sort_three(a, b);
}

void	sort(t_stack **a, t_stack **b)
{
	t_stack	*min_cost;

	pusher(a, b);
	while (stack_size(*b) > 0)
	{
		min_cost = min_cost_finder(*a, *b);
		execute_cost(min_cost, a, b);
	}
	if (min_position(*a) <= stack_size(*a) / 2)
		while (!sorted(*a))
			rotate(a, b, 'a');
	else
		while (!sorted(*a))
			reverse_rotate(a, b, 'a');
}
