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

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape || keysym == 113)
		close_game(data);
	if (keysym == XK_a)
		player_move(data, XK_a);
	if (keysym == XK_s)
		player_move(data, XK_s);
	if (keysym == XK_d)
		player_move(data, XK_d);
	if (keysym == XK_w)
		player_move(data, XK_w);
	return (0);
}

void	render_player(t_data *data, int y, int x)
{
	if (data->player.keysym == XK_a)
		mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, data->player.xpm_ptr_left, x * data->player.width, y * data->player.height);
	if (data->player.keysym == XK_s)
		mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, data->player.xpm_ptr_down, x * data->player.width, y * data->player.height);
	if (data->player.keysym == XK_d)
		mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, data->player.xpm_ptr_right, x * data->player.width, y * data->player.height);
	if (data->player.keysym == XK_w)
		mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, data->player.xpm_ptr, x * data->player.width, y * data->player.height);
}

void	render_exit(t_data *data, int y, int x)
{
	if (data->struc_map->collect > 0)
		mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, data->exit.xpm_ptr, x * data->exit.width, y * data->exit.height);
	else
		mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, data->exit.xpm_ptr_down, x * data->exit.width, y * data->exit.height);
}

void	render_somthing(t_data *data, t_image *xpm_ptr, int x, int y)
{
	mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, xpm_ptr,
		x * data->wall.width, y * data->wall.height);
}

int	render(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (data->win_ptr == NULL)
		return (1);
	while (data->struc_map->map[y])
	{
		while (data->struc_map->map[y][x])
		{
			if (data->struc_map->map[y][x] == '1')
				render_somthing (data, data->wall.xpm_ptr, x, y);
			else if (data->struc_map->map[y][x] == 'P')
				render_player(data, y, x);
			else if (data->struc_map->map[y][x] == '0')
				render_somthing (data, data->floor.xpm_ptr, x, y);
			else if (data->struc_map->map[y][x] == 'C')
				render_somthing (data, data->collect.xpm_ptr, x, y);
			else if (data->struc_map->map[y][x] == 'E')
				render_exit(data, y, x);
			x++;
		}
		y++;
		x = 0;
	}
	return (0);
}

void	init_textures(t_data *data)
{
	data->wall.xpm_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "wall.xpm",
			&data->wall.width, &data->wall.height);
	data->player.xpm_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "tank_up.xpm",
			&data->player.width, &data->player.height);
	data->player.xpm_ptr_right = mlx_xpm_file_to_image(data->mlx_ptr,
			"tank_right.xpm", &data->player.width, &data->player.height);
	data->player.xpm_ptr_down = mlx_xpm_file_to_image(data->mlx_ptr,
			"tank_down.xpm", &data->player.width, &data->player.height);
	data->player.xpm_ptr_left = mlx_xpm_file_to_image(data->mlx_ptr,
			"tank_left.xpm", &data->player.width, &data->player.height);
	data->floor.xpm_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "black_back.xpm",
			&data->floor.width, &data->floor.height);
	data->collect.xpm_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "collect.xpm",
			&data->collect.width, &data->collect.height);
	data->exit.xpm_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "closed_door.xpm",
			&data->exit.width, &data->exit.height);
	data->exit.xpm_ptr_down = mlx_xpm_file_to_image(data->mlx_ptr,
			"opened_door.xpm", &data->exit.width, &data->exit.height);
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
	data.player.x = data.struc_map->player_x;
	data.player.y = data.struc_map->player_y;
	data.player.keysym = XK_w;
	// render(&data);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	/* we will exit the loop if there's no window left, and execute this code */
	// mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}