/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:01:50 by  rabbie           #+#    #+#             */
/*   Updated: 2022/04/27 20:24:04 by rabbie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
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

void	init_textures(t_data *data)
{
	data->wall.xpm_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "xpms/wall.xpm",
			&data->wall.width, &data->wall.height);
	data->player.xpm_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"xpms/tank_up.xpm", &data->player.width, &data->player.height);
	data->player.xpm_ptr_right = mlx_xpm_file_to_image(data->mlx_ptr,
			"xpms/tank_right.xpm", &data->player.width, &data->player.height);
	data->player.xpm_ptr_down = mlx_xpm_file_to_image(data->mlx_ptr,
			"xpms/tank_down.xpm", &data->player.width, &data->player.height);
	data->player.xpm_ptr_left = mlx_xpm_file_to_image(data->mlx_ptr,
			"xpms/tank_left.xpm", &data->player.width, &data->player.height);
	data->floor.xpm_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"xpms/black_back.xpm", &data->floor.width, &data->floor.height);
	data->collect.xpm_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"xpms/collect.xpm", &data->collect.width, &data->collect.height);
	data->exit.xpm_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"xpms/closed_door.xpm", &data->exit.width, &data->exit.height);
	data->exit.xpm_ptr_down = mlx_xpm_file_to_image(data->mlx_ptr,
			"xpms/opened_door.xpm", &data->exit.width, &data->exit.height);
	data->player.x = data->struc_map->player_x;
	data->player.y = data->struc_map->player_y;
	data->player.keysym = XK_w;
	data->steps = 0;
}

int	destroy_hook(int keysym, t_data *data)
{
	(void)keysym;
	close_game(data);
	return (0);
}

int	main(int av, char **ac)
{
	t_data	data;

	data.struc_map = map(ac[1], av);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.struc_map->width * 50,
			data.struc_map->height * 50, "my window");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	init_textures(&data);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, 1L << 17, destroy_hook, &data);
	mlx_loop(data.mlx_ptr);
}
