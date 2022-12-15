/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:05:46 by amorais-          #+#    #+#             */
/*   Updated: 2022/12/15 12:10:10 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"
# include "getnextline/get_next_line.h"

void	error_management(int argv, char **argc, t_stack **a, t_stack **b);
t_stack	*a_creator(char	**argc, int arg);
void	checker_reverse_rotate(t_stack **a, t_stack **b, int c);
void	checker_rotate(t_stack **a, t_stack **b, int c);
void	checker_swap(t_stack **a, t_stack **b, int c);
void	checker_push(t_stack **a, t_stack **b);
void	checker_stack_clear(t_stack **a);
int		checker_stack_size(t_stack *a);
#endif