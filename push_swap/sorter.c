/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:09:33 by amorais-          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/12/05 11:23:22 by amorais-         ###   ########.fr       */
=======
/*   Updated: 2022/12/07 17:17:45 by amorais-         ###   ########.fr       */
>>>>>>> 9897c6aad4c9165fa09e3301242a1c0eed772b20
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

<<<<<<< HEAD
void	print_rule(int rule)
{
	if (rule == 1)
		ft_printf("sa\n");
	else if (rule == 2)
		ft_printf("sb\n");
	else if (rule == 3)
		ft_printf("ss\n");
	else if (rule == 4)
		ft_printf("pa\n");
	else if (rule == 5)
		ft_printf("pb\n");
	else if (rule == 6)
		ft_printf("ra\n");
	else if (rule == 7)
		ft_printf("rb\n");
	else if (rule == 8)
		ft_printf("rr\n");
	else if (rule == 9)
		ft_printf("rra\n");
	else if (rule == 10)
		ft_printf("rrb\n");
	else if (rule == 11)
=======
void	rule_printer(int rule)
{
	if (rule == 1)
		ft_printf("sa\n");
	if (rule == 2)
		ft_printf("sb\n");
	if (rule == 3)
		ft_printf("ss\n");
	if (rule == 4)
		ft_printf("pa\n");
	if (rule == 5)
		ft_printf("pb\n");
	if (rule == 6)
		ft_printf("ra\n");
	if (rule == 7)
		ft_printf("rb\n");
	if (rule == 8)
		ft_printf("rr\n");
	if (rule == 9)
		ft_printf("rra\n");
	if (rule == 10)
		ft_printf("rrb\n");
	if (rule == 11)
>>>>>>> 9897c6aad4c9165fa09e3301242a1c0eed772b20
		ft_printf("rrr\n");
}

void	rules(int rule, int *a, int *b, int *counter_a, int *counter_b)
{
	if (rule == 1)
		ft_swap(&a[0], &a[1], *counter_a);
	else if (rule == 2)
		ft_swap(&b[0], &b[1], *counter_b);
	else if (rule == 3)
	{
		ft_swap(&a[0], &a[1], *counter_a);
		ft_swap(&b[0], &b[1], *counter_b);
	}
	else if (rule == 4)
		push(a, b, counter_a, counter_b);
	else if (rule == 5)
		push(b, a, counter_b, counter_a);
	else if (rule == 6 || rule == 7 || rule == 8)
		rotate(a, b, rule, *counter_a, *counter_b);
	else if (rule == 9 || rule == 10 || rule == 11)
		reverse_rotate(a, b, rule, *counter_a, *counter_b);
<<<<<<< HEAD
	print_rule(rule);
=======
	rule_printer(rule);
>>>>>>> 9897c6aad4c9165fa09e3301242a1c0eed772b20
}

void	sorter(int *a, int *b, int counter_a, int counter_b)
{
<<<<<<< HEAD
	int	i;
	int	x;
	
	
	i = 0;
	x = 0;
=======
	int	i = 0;
	int	x = 0;

>>>>>>> 9897c6aad4c9165fa09e3301242a1c0eed772b20
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