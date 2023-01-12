/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:17:21 by amorais-          #+#    #+#             */
/*   Updated: 2023/01/12 15:22:20 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	is_char_valid(char	c)
{
	return (c == '1' || c == '0' || c == 'P' || c == 'E' || c == 'C');
}

int	map_validator(t_map	map)
{
	int	i;
	int	j;

	i = 0;
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j])
			if (!is_char_valid(map.map[i][j++]))
				return (0);
		if (j != map.dimension.x)
			return (0);
		i++;
	}
	return (1);
}
