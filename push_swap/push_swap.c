/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:30:04 by amorais-          #+#    #+#             */
/*   Updated: 2022/12/04 19:17:48 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_check(char **argc, int arg)
{
	int	i;
	int	j;
	int	x;

	i = arg;
	while (argc[i])
	{
		j = arg;
		x = 0;
		while (argc[i][x])
			if (!ft_isdigit(argc[i][x++]) && argc[i][x - 1] != '-')
				return (1);
		while (j < i)
			if (ft_atoi(argc[j++]) == ft_atoi(argc[i]) \
			|| ft_atoi(argc[i]) > INT_MAX || ft_atoi(argc[i]) < INT_MIN)
				return (1);
		i++;
	}
	return (0);
}

int	*a_creator(int argv, char **argc, int *counter, int arg)
{
	int	i;
	int	*a;

	a = malloc(sizeof(int) * (argv - arg));
	if (!a)
		return (NULL);
	i = 0;
	while (i < argv - arg)
	{
		a[i] = ft_atoi(argc[i + arg]);
		i++;
		(*counter)++;
	}
	return (a);
}

int	*b_creator(int argv, int size)
{
	int	*b;

	if (argv == 2)
		b = malloc(sizeof(int) * size);
	else
		b = malloc(sizeof(int) * (argv - 1));
	if (!b)
		return (NULL);
	return (b);
}

int	main(int argv, char **argc)
{
	int	*a;
	int	*b;
	int	counter_a;
	int	counter_b;

	if (argv <= 1)
		exit(0) ;
	if (argv > 2 && error_check(argc, 1))
		return (ft_printf("Error\n"));
	if (argv == 2 && error_check(ft_split(argc[1], ' '), 0))
		return (ft_printf("Error\n"));
	counter_a = 0;
	counter_b = 0;
	if (argv > 2)
		a = a_creator(argv, argc, &counter_a, 1);
	else
		a = a_creator(split_size(ft_split(argc[1], ' ')), ft_split(argc[1], ' '), &counter_a, 0);
	b = b_creator(argv, split_size(ft_split(argc[1], ' ')));
	sorter(a, b, counter_a, counter_b);
	free (a);
	free (b);
}
