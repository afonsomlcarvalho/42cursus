/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:23:36 by amorais-          #+#    #+#             */
/*   Updated: 2022/12/08 12:41:32 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_min_to_beg(int *a, int counter_a)
{
	int min;
	int	i;

	min = 0;
	i = 1;
	while (i < counter_a)
	{
		if (a[min] > a[i])
			min = i;
		i++;
	}
	if (min > counter_a / 2)
		while (min++ < counter_a)
			reverse_rotate(a, counter_a, 'a');
	else
		while (min-- > 0)
			rotate(a, counter_a, 'a');
}

void	sorter(int *a, int *b, int counter_a, int counter_b)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	sort_four_to_six(a, b, &counter_a, &counter_b);
	ft_printf("a: ");
	while (counter_a-- > 0)
	{
		ft_printf("%d ", a[i]);
		i++;
	}
	ft_printf("\nb: ");
	while (counter_b-- > 0)
	{
		ft_printf("%d ", b[x]);
		x++;
	}
}