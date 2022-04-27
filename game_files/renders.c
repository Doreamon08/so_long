/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:17:45 by rabbie            #+#    #+#             */
/*   Updated: 2022/04/24 17:58:29 by rabbie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	render_player(t_data *data, int y, int x)
{
	if (data->player.keysym == XK_a)
		mlx_put_image_to_window (data->mlx_ptr, data->win_ptr,
			data->player.xpm_ptr_left, x * data->player.width,
			y * data->player.height);
	if (data->player.keysym == XK_s)
		mlx_put_image_to_window (data->mlx_ptr, data->win_ptr,
			data->player.xpm_ptr_down, x * data->player.width,
			y * data->player.height);
	if (data->player.keysym == XK_d)
		mlx_put_image_to_window (data->mlx_ptr, data->win_ptr,
			data->player.xpm_ptr_right, x * data->player.width,
			y * data->player.height);
	if (data->player.keysym == XK_w)
		mlx_put_image_to_window (data->mlx_ptr, data->win_ptr,
			data->player.xpm_ptr, x * data->player.width,
			y * data->player.height);
}

void	render_exit(t_data *data, int y, int x)
{
	if (data->struc_map->collect > 0)
		mlx_put_image_to_window (data->mlx_ptr, data->win_ptr,
			data->exit.xpm_ptr, x * data->exit.width, y * data->exit.height);
	else
		mlx_put_image_to_window (data->mlx_ptr, data->win_ptr,
			data->exit.xpm_ptr_down, x * data->exit.width,
			y * data->exit.height);
}

void	render_somthing(t_data *data, t_image *xpm_ptr, int x, int y)
{
	mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, xpm_ptr,
		x * data->wall.width, y * data->wall.height);
}

int	render(t_data *data)
{
	data->y = 0;
	data->x = 0;
	if (data->win_ptr == NULL)
		return (1);
	while (data->struc_map->map[data->y])
	{
		while (data->struc_map->map[data->y][data->x])
		{
			if (data->struc_map->map[data->y][data->x] == '1')
				render_somthing (data, data->wall.xpm_ptr, data->x, data->y);
			else if (data->struc_map->map[data->y][data->x] == 'P')
				render_player(data, data->y, data->x);
			else if (data->struc_map->map[data->y][data->x] == '0')
				render_somthing (data, data->floor.xpm_ptr, data->x, data->y);
			else if (data->struc_map->map[data->y][data->x] == 'C')
				render_somthing (data, data->collect.xpm_ptr, data->x, data->y);
			else if (data->struc_map->map[data->y][data->x] == 'E')
				render_exit(data, data->y, data->x);
			data->x++;
		}
		data->y++;
		data->x = 0;
	}
	return (0);
}
