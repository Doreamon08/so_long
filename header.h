/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:44:54 by rabbie            #+#    #+#             */
/*   Updated: 2022/04/24 14:20:33 by rabbie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <stdio.h>

# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>

# include "get_next_line/get_next_line.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

# define MLX_ERROR 1

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFFFF

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
	int		collect;
	int		enemies;
	int		player;
	int		player_x;
	int		player_y;
	int		exit;
	int		walls;
	int		floor;
	int		x;
	int		y;
}				t_map;

typedef struct s_image
{
	void	*xpm_ptr;
	void	*xpm_ptr_right;
	void	*xpm_ptr_down;
	void	*xpm_ptr_left;
	int		width;
	int		height;
	int		x;
	int		y;
	int		keysym;
}				t_image;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
	t_img	img;
	t_map	*struc_map;
	t_image	wall;
	t_image	floor;
	t_image	collect;
	t_image	player;
	t_image	exit;
}				t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}				t_rect;

void	img_pix_put(t_img *img, int x, int y, int color);
void	errors(char *str);
void	map_error(t_map *struc_map, char *str);
void	free_char(char **temp);
t_map	*check_valid_map(char **map);
t_map	*map(char *map_name, int av);
int		render(t_data *data);
void	player_move(t_data *data, int keysym);
void	close_game(t_data *data);

#endif