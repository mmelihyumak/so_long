/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:39:27 by muyumak           #+#    #+#             */
/*   Updated: 2023/01/29 06:45:53 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct	s_map
{
	char	**lines;
	char	*wall_path;
	char	*player_path;
	char	*collectible_path;
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img_wall;
	void	*img_player;
	void	*img_collectible;
	int		width;
	int		height;	
	int		len_of_line;
	int		number_of_p;
	int		number_of_c;
	int		number_of_e;
	int		player_x;
	int		player_y;
}t_map;

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		split_len(char **lines);
int		check_filename(char *argv);
int		get_map_lines(t_map *map, char *filename);
int		check_map(t_map *map);
int		map_len(char *filename);

#endif
