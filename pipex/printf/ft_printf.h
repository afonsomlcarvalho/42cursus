/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:52:41 by amorais-          #+#    #+#             */
/*   Updated: 2022/12/17 12:21:27 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "../libft/libft.h"

int		ft_printf(const char *s, ...);
int		nbrlen(long int nb);
void	ft_putnbr_unsigned(unsigned int n, int fd);
int		ft_putptr(unsigned long int n, int len, int check);
int		ft_puthexa(unsigned long int n, int len, int upper);

#endif