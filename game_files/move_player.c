/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:35:06 by rabbie            #+#    #+#             */
/*   Updated: 2022/04/27 20:25:02 by rabbie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	player_move_d(t_data *data, int keysym)
{
	data->player.keysym = keysym;
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
	data->steps++;
	write (1, "Steps: ", 7);
	ft_putnbr_fd(data->steps, 1);
	write(1, "\n", 1);
}

void	player_move_s(t_data *data, int keysym)
{
	data->player.keysym = keysym;
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
	data->steps++;
	write (1, "Steps: ", 7);
	ft_putnbr_fd(data->steps, 1);
	write(1, "\n", 1);
}

void	player_move_w(t_data *data, int keysym)
{
	data->player.keysym = keysym;
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
	data->steps++;
	write (1, "Steps: ", 7);
	ft_putnbr_fd(data->steps, 1);
	write(1, "\n", 1);
}

void	player_move_a(t_data *data, int keysym)
{
	data->player.keysym = keysym;
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
	data->steps++;
	write (1, "Steps: ", 7);
	ft_putnbr_fd(data->steps, 1);
	write(1, "\n", 1);
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
