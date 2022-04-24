/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:53:32 by rabbie            #+#    #+#             */
/*   Updated: 2022/04/24 13:01:56 by rabbie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	close_game(t_data *data)
{
	data->struc_map->x = 0;
	data->struc_map->y = 0;

	while (data->struc_map->map[data->struc_map->y])
	{
		free(data->struc_map->map[data->struc_map->y]);
		data->struc_map->y++;
	}
	free(data->struc_map->map);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
}
