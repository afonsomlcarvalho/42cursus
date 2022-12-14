/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:58:34 by amorais-          #+#    #+#             */
/*   Updated: 2022/12/14 11:06:09 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H	
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct list
{
	long int	number;
	struct list	*next;
}	t_stack;

void	push(t_stack **a, t_stack **b, char c);
void	swap(t_stack **a, char c);
void	rotate(t_stack **a, t_stack **b, char c);
void	printer(t_stack *a, t_stack *b);
void	reverse_rotate(t_stack **a, t_stack **b, char c);
int		stack_size(t_stack *a);
void	sorter(t_stack *a, t_stack *b);
int		sorted(t_stack *a);
t_stack	*stc_last(t_stack *a);
void	sort_three(t_stack **a, t_stack **b);
int		min_position(t_stack *a);
void	sort_four_to_five(t_stack **a, t_stack **b);
int		position(t_stack *current, t_stack *a);
int		position_in_other(int current, t_stack *a);
int		cost(t_stack *current, t_stack *a, t_stack *b);
void	sort(t_stack **a, t_stack **b);
int		max_position(t_stack *a);
void	stack_clear(t_stack **a);
int		min(t_stack *a);
#endif