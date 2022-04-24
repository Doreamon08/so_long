/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:35:06 by rabbie            #+#    #+#             */
/*   Updated: 2022/04/24 13:05:02 by rabbie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	player_move_d(t_data *data, int keysym)
{
	data->player.keysym = XK_d;
	if (data->struc_map->map[data->player.y][data->player.x + 1] == '1' ||
		(data->struc_map->map[data->player.y][data->player.x + 1] == 'E' &&
		data->struc_map->collect != 0))
		return ;
	if (data->struc_map->map[data->player.y][data->player.x + 1] == 'E' &&
			data->struc_map->collect == 0)
		close_game(data);
	if (data->struc_map->map[data->player.y][data->player.x + 1] == 'C')
		data->struc_map->collect--;
	data->struc_map->map[data->player.y][data->player.x] = '0';
	data->struc_map->map[data->player.y][data->player.x + 1] = 'P';
	data->player.x++;
}

void	player_move_s(t_data *data, int keysym)
{
	data->player.keysym = XK_s;
	if (data->struc_map->map[data->player.y + 1][data->player.x] == '1' ||
		(data->struc_map->map[data->player.y + 1][data->player.x] == 'E' &&
		data->struc_map->collect != 0))
		return ;
	if (data->struc_map->map[data->player.y + 1][data->player.x] == 'E' &&
			data->struc_map->collect == 0)
		close_game(data);
	if (data->struc_map->map[data->player.y + 1][data->player.x] == 'C')
		data->struc_map->collect--;
	data->struc_map->map[data->player.y][data->player.x] = '0';
	data->struc_map->map[data->player.y + 1][data->player.x] = 'P';
	data->player.y++;
}

void	player_move_w(t_data *data, int keysym)
{
	data->player.keysym = XK_w;
	if (data->struc_map->map[data->player.y - 1][data->player.x] == '1' ||
		(data->struc_map->map[data->player.y - 1][data->player.x] == 'E' &&
		data->struc_map->collect != 0))
		return ;
	if (data->struc_map->map[data->player.y - 1][data->player.x] == 'E' &&
			data->struc_map->collect == 0)
		close_game(data);	
	if (data->struc_map->map[data->player.y - 1][data->player.x] == 'C')
		data->struc_map->collect--;
	data->struc_map->map[data->player.y][data->player.x] = '0';
	data->struc_map->map[data->player.y - 1][data->player.x] = 'P';
	data->player.y--;
}

void	player_move_a(t_data *data, int keysym)
{
	data->player.keysym = XK_a;
	if (data->struc_map->map[data->player.y][data->player.x - 1] == '1' ||
		(data->struc_map->map[data->player.y][data->player.x - 1] == 'E' &&
			data->struc_map->collect != 0))
		return ;
	if (data->struc_map->map[data->player.y][data->player.x - 1] == 'E' &&
			data->struc_map->collect == 0)
		close_game(data);
	if (data->struc_map->map[data->player.y][data->player.x - 1] == 'C')
		data->struc_map->collect--;
	data->struc_map->map[data->player.y][data->player.x] = '0';
	data->struc_map->map[data->player.y][data->player.x - 1] = 'P';
	data->player.x--;
}

void	player_move(t_data *data, int keysym)
{
	if (keysym == XK_d)
		player_move_d(data, keysym);
	if (keysym == XK_s)
		player_move_s(data, keysym);
	if (keysym == XK_w)
		player_move_w(data, keysym);
	if (keysym == XK_a)
		player_move_a(data, keysym);
}
