/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:56:17 by amorais-          #+#    #+#             */
/*   Updated: 2023/01/04 11:42:49 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a, t_stack **b)
{
	while (!sorted(*a))
	{
		if ((*a)->number > (*a)->next->number && (*a)->number > \
		stc_last(*a)->number)
			rotate(a, b, 'a');
		if ((*a)->number > (*a)->next->number && (*a)->number < \
		stc_last(*a)->number)
			swap(a, 'a');
		if ((*a)->number < (*a)->next->number && (*a)->next->number > \
		stc_last(*a)->number)
			reverse_rotate(a, b, 'a');
	}
}

void	sort_four_to_five(t_stack **a, t_stack **b)
{
	while (stack_size(*a) > 3)
	{
		while (min_position(*a))
		{
			if (min_position(*a) <= stack_size(*a) / 2)
				rotate(a, b, 'a');
			else
				reverse_rotate(a, b, 'a');
		}
		push(a, b, 'b');
	}
	sort_three(a, b);
	while (stack_size(*b) > 0)
		push(b, a, 'a');
}

void	sorter(t_stack *a, t_stack *b)
{
	if (stack_size(a) == 2)
		swap(&a, 'a');
	else if (stack_size(a) == 3)
		sort_three(&a, &b);
	//else if (stack_size(a) <= 5)
		//sort_four_to_five(&a, &b);
	else
		sort(&a, &b);
	stack_clear(&a);
	if (b)
		stack_clear(&b);
}
