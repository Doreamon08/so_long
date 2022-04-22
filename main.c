/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:01:509 by rabbie            #+#    #+#             */
/*   Updated: 2022/04/19 16:38:44 by rabbie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int	render_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

void	render_background(t_img *img, int color, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->struc_map->width * 20)
	{
		j = 0;
		while (j < data->struc_map->height * 150)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}

int	handle_no_event(void *game)
{
	return (0);
}

void	player_move(t_data *data, int keysym)
{
	char	temp;

	if (keysym == XK_d)
	{
		data->struc_map->map[data->player.y][data->player.x] = '0';
		data->struc_map->map[data->player.y][data->player.x + 1] = 'P';
		data->player.x++;
		data->player.keysym = XK_d;
	}
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	if (keysym == XK_Left)
		data->x = data->x - 150;
	if (keysym == XK_Down)
		data->y = data->y + 150;
	if (keysym == XK_d)
		player_move(data, XK_d);
	if (keysym == XK_Up)
		data->y = data->y - 150;
	return (0);
}

void	render_player(t_data *data, int y, int x)
{
	if (data->player.keysym == XK_Left)
		data->x = data->x - 150;
	if (data->player.keysym == XK_Down)
		data->y = data->y + 150;
	if (data->player.keysym == XK_d)
		mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, data->player.xpm_ptr_right, x * data->player.width, y * data->player.height);
	if (data->player.keysym == XK_Up)
		mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, data->player.xpm_ptr, x * data->player.width, y * data->player.height);;
}

int	render(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (data->win_ptr == NULL)
		return (1);
	// render_background(&data->img, WHITE_PIXEL, data);
	while (data->struc_map->map[y])
	{
		while (data->struc_map->map[y][x])
		{
			// mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, data->floor.xpm_ptr, x * data->floor.width, y * data->floor.height);
			if (data->struc_map->map[y][x] == '1')
				mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, data->wall.xpm_ptr, x * data->wall.width, y * data->wall.height);
			else if (data->struc_map->map[y][x] == 'P')
				render_player(data, y, x);
			x++;
		}
		y++;
		x = 0;
	}
	return (0);
}

void	init_textures(t_data *data)
{
	data->wall.xpm_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "wall.xpm", &data->wall.width, &data->wall.height);
	data->floor.xpm_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "floor.xpm", &data->floor.width, &data->floor.height);
	data->player.xpm_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "tank_up.xpm", &data->player.width, &data->player.height);
	data->player.xpm_ptr_right = mlx_xpm_file_to_image(data->mlx_ptr, "tank_right.xpm", &data->player.width, &data->player.height);
	data->player.xpm_ptr_down = mlx_xpm_file_to_image(data->mlx_ptr, "tank_down.xpm", &data->player.width, &data->player.height);
	data->player.xpm_ptr_left = mlx_xpm_file_to_image(data->mlx_ptr, "tank_left.xpm", &data->player.width, &data->player.height);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (img->line_len * y + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int	main(int av, char **ac)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	data.struc_map = map(ac[1], av);
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.struc_map->width * 50, data.struc_map->height * 50,
								"my window");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	init_textures(&data);
	/* Setup hooks */ 
	data.player.x = 1;
	data.player.y = 3;
	data.player.keysym = XK_Up;
	// render(&data);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	// mlx_put_image_to_window (data.mlx_ptr, data.win_ptr, data.wall.xpm_ptr, 4 * data.wall.width, 3 * data.wall.height);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);

	mlx_loop(data.mlx_ptr);
	
	/* we will exit the loop if there's no window left, and execute this code */
	// mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	
}