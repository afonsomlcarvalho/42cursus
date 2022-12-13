/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:57:40 by amorais-          #+#    #+#             */
/*   Updated: 2022/12/13 17:20:19 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free (array);
}

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
	if (arg == 0)
		split_free(argc);
	return (0);
}

t_stack	*a_creator(char	**argc, int arg)
{
	t_stack	*a;
	int	m;

	m = arg;
	a = malloc(sizeof(t_stack));
	a->number = ft_atoi(argc[arg]);
	a->next = NULL;
	if (argc[++arg])
		a->next = a_creator(argc, arg);
	if (m == 0)
		split_free(argc);
	return (a);
}

int	sorted(t_stack *a)
{
	t_stack	*current;

	current = a;
	while (current->next)
	{
		if (current->number > current->next->number)
			return (0);
		current = current->next;
	}
	return (1);
}

int	main(int argv, char **argc)
{
	t_stack	*a;
	t_stack	*b;

	if (argv <= 1)
		exit(0);
	if ((argv > 2 && error_check(argc, 1)) || (argv == 2 && \
	error_check(ft_split(argc[1], ' '), 0)))
		return (ft_printf("Error\n"));
	if (argv == 2)
		a = a_creator(ft_split(argc[1], ' '), 0);
	else
		a = a_creator(argc, 1);
	b = NULL;
	if (sorted(a))
		exit(0);
	sorter(a, b);
}
