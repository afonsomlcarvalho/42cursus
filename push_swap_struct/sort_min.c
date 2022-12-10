/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:31:56 by amorais-          #+#    #+#             */
/*   Updated: 2022/12/10 14:20:44 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(stack **a)
{
	while(!sorted(*a))
	{
		if ((*a)->number > (*a)->next->number && (*a)->number > stc_last(*a)->number)
			rotate(a, 'a');
		if ((*a)->number > (*a)->next->number && (*a)->number < stc_last(*a)->number)
			swap(a, 'a');
		if ((*a)->number < (*a)->next->number && (*a)->next->number > stc_last(*a)->number)
			reverse_rotate(a, 'a');
	}
}

void	sort_four_to_five(stack **a, stack **b)
{
	while (stack_size(*a) > 3)
	{
		while (min_position(*a))
		{
			if (min_position(*a) <= stack_size(*a) / 2)
				rotate(a, 'a');
			else
				reverse_rotate(a, 'a');
		}
		push(b, a, 'b');
	}
	sort_three(a);
	while (stack_size(*b) > 0)
		push(a, b, 'a');
}
