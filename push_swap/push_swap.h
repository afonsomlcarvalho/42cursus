/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:12:52 by amorais-          #+#    #+#             */
/*   Updated: 2022/12/07 17:17:24 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
void	ft_swap(int *a, int *b, int counter);
void	push(int *a, int *b, int *counter_a, int *counter_b);
void	rotate(int *a, int *b, int rule, int counter_a, int counter_b);
void	reverse_rotate(int *a, int *b, int rule, int counter_a, int counter_b);
void	rules(int rule, int *a, int *b, int *counter_a, int *counter_b);
int		split_size(char **array);
void	sorter(int *a, int *b, int counter_a, int counter_b);
void	sort_three(int *a, int *b, int counter_a, int counter_b);
#endif