/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:53:32 by rabbie            #+#    #+#             */
/*   Updated: 2022/04/27 20:07:58 by rabbie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void	close_images(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->collect.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->exit.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->exit.xpm_ptr_down);
	mlx_destroy_image(data->mlx_ptr, data->wall.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->floor.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->player.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->player.xpm_ptr_down);
	mlx_destroy_image(data->mlx_ptr, data->player.xpm_ptr_left);
	mlx_destroy_image(data->mlx_ptr, data->player.xpm_ptr_right);
}

void	close_game(t_data *data)
{
	data->struc_map->y = 0;
	while (data->struc_map->map[data->struc_map->y])
	{
		free(data->struc_map->map[data->struc_map->y]);
		data->struc_map->map[data->struc_map->y] = NULL;
		data->struc_map->y++;
	}
	free(data->struc_map->map);
	data->struc_map->map = NULL;
	free(data->struc_map);
	close_images(data);
	if (data->win_ptr)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}
