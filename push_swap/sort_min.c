/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:57:16 by amorais-          #+#    #+#             */
/*   Updated: 2022/12/07 17:17:14 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(int *a, int *b, int counter_a, int counter_b)
{
	while (!(a[0] < a[1] && a[1] < a[2]))
	{	
		if (a[0] > a[1] && a[0] > a[2])
			rules(6, a, b, counter_a, counter_b);
		if (a[0] > a[1] && a[2] > a[0])
			rules(1, a, b, counter_a, counter_b);
		if (a[1] > a[0] && a[1] > a[2])
			rules(9, a, b, counter_a, counter_b);
	}
}

//void	sort_four_to_six()