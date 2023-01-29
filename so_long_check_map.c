/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 01:29:38 by muyumak           #+#    #+#             */
/*   Updated: 2023/01/29 03:39:04 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Dosya ismini kontrol eder.
int		check_filename(char *filename)
{
	int	len_of_filename;

	len_of_filename = ft_strlen(filename);
	if (filename[len_of_filename -1] != 'r' || filename[len_of_filename -2] != 'e'
		|| filename[len_of_filename -3] != 'b' || filename[len_of_filename -4] != '.')
		return (0);
	return (1);
}

int		check_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->lines[i])
	{
		j = 0;
		while (map->lines[i][j])
		{
			if (map->lines[i][j] == 'P')
				map->number_of_p += 1;
			else if (map->lines[i][j] == 'E')
				map->number_of_e += 1;
			else if (map->lines[i][j] == 'C')
				map->number_of_c += 1;
			j++;
		}
		i++;
	}
	if (map->number_of_c < 1 || map->number_of_p != 1 || map->number_of_e != 1)
		return (0);
	return (1);
}