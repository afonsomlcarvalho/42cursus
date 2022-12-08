/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:12:52 by amorais-          #+#    #+#             */
/*   Updated: 2022/12/08 12:43:04 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
void	ft_swap(int *a, int *b, int counter, char array);
void	push(int *a, int *b, int *counter_a, int *counter_b);
void	rotate(int *a, int counter_a, char array);
void	reverse_rotate(int *a, int counter_a, char array);
int		split_size(char **array);
void	sorter(int *a, int *b, int counter_a, int counter_b);
void	sort_three(int *a, int counter_a, char array);
void	sort_four_to_six(int *a, int *b, int *counter_a, int *counter_b);
void	reverse_sort_b(int *a, int *b, int *counter_a, int *counter_b);
int		sorted(int *a, int counter_a);
void	get_min_to_beg(int *a, int counter_a);
#endif