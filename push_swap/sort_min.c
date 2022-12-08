/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:57:16 by amorais-          #+#    #+#             */
/*   Updated: 2022/12/08 13:25:29 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(int *a, int counter)
{
	if (a[0] > a[1])
		ft_swap(&a[0], &a[1], counter, 'a');
}

void	sort_three(int *a, int counter_a, char array)
{
	while (!(sorted(a, counter_a)))
	{	
		if (a[0] > a[1] && a[0] > a[2])
			rotate(a, counter_a, array);
		if (a[0] > a[1] && a[2] > a[0])
			ft_swap(&a[0], &a[1], counter_a, array);
		if (a[1] > a[0] && a[1] > a[2])
			reverse_rotate(a, counter_a, array);
	}
}

void	sort_four_to_six(int *a, int *b, int *counter_a, int *counter_b)
{
	while (*counter_a > 3)
	{
		get_min_to_beg(a, *counter_a);
		push(b, a, counter_b, counter_a);
		ft_printf("pb\n");
	}
	sort_three(a, *counter_a, 'a');
	while (*counter_b > 0)
	{
		push(a, b, counter_a, counter_b);
		ft_printf("pa\n");
	}
}