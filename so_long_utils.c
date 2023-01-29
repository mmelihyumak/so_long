/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 01:23:26 by muyumak           #+#    #+#             */
/*   Updated: 2023/01/29 04:01:35 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Haritada satır sayısını sayar.
int	split_len(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
		i++;
	return (i);
}

int	map_len(char *filename)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		return (0);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

int		get_map_lines(t_map *map, char *filename)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		return (0);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		map->lines[i] = line;
		map->lines[i][ft_strlen(line)] = 0;
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (1);
}