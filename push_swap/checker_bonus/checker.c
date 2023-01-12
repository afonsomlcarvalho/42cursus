/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:49:41 by amorais-          #+#    #+#             */
/*   Updated: 2023/01/12 13:23:39 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	checker_stack_size(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

void	checker_stack_clear(t_stack **a)
{
	t_stack	*temp;

	while (*a)
	{
		temp = (*a)->next;
		free(*a);
		*a = temp;
	}
	*a = NULL;
}

void	apply_rules(char *rule, t_stack	**a, t_stack **b)
{
	if (!ft_strncmp(rule, "sa\n", 3))
		checker_swap(a, b, 0);
	else if (!ft_strncmp(rule, "sb\n", 3))
		checker_swap(b, a, 0);
	else if (!ft_strncmp(rule, "ss\n", 3))
		checker_swap(a, b, 1);
	else if (!ft_strncmp(rule, "pa\n", 3))
		checker_push(b, a);
	else if (!ft_strncmp(rule, "pb\n", 3))
		checker_push(a, b);
	else if (!ft_strncmp(rule, "ra\n", 3))
		checker_rotate(a, b, 0);
	else if (!ft_strncmp(rule, "rb\n", 3))
		checker_rotate(b, a, 0);
	else if (!ft_strncmp(rule, "rr\n", 3))
		checker_rotate(a, b, 1);
	else if (!ft_strncmp(rule, "rra\n", 4))
		checker_reverse_rotate(a, b, 0);
	else if (!ft_strncmp(rule, "rrb\n", 4))
		checker_reverse_rotate(b, a, 0);
	else if (!ft_strncmp(rule, "rrr\n", 4))
		checker_reverse_rotate(a, b, 1);
	else
		error_management(0, (char **) NULL, a, b);
}

int	main(int argv, char **argc)
{
	t_stack	*a;
	t_stack	*b;
	char	*rule;

	error_management(argv, argc, (t_stack **) NULL, (t_stack **) NULL);
	if (argv == 2)
		a = a_creator(ft_split(argc[1], ' '), 0);
	else
		a = a_creator(argc, 1);
	b = NULL;
	rule = get_next_line(0);
	while (rule)
	{
		apply_rules(rule, &a, &b);
		free(rule);
		rule = get_next_line(0);
	}
	free(rule);
	if (sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	checker_stack_clear(&a);
	checker_stack_clear(&b);
}
