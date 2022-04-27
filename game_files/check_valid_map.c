/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:58:17 by rabbie            #+#    #+#             */
/*   Updated: 2022/04/27 20:06:08 by rabbie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	check_hw(t_map *struc_map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (struc_map->map[struc_map->height])
		struc_map->height++;
	if (struc_map->height < 3)
		map_error(struc_map, "Height too low\n");
	while (struc_map->map[0][struc_map->width])
		struc_map->width++;
	if (struc_map->width < 5)
		map_error(struc_map, "Width too low\n");
	while (struc_map->map[y])
	{
		while (struc_map->map[y][x])
			x++;
		if (x != struc_map->width)
			map_error(struc_map, "Width error\n");
		y++;
		x = 0;
	}
}

void	check_walls(t_map *struc_map)
{
	int	x;
	int	y;

	y = 1;
	x = 0;
	while (struc_map->map[0][x])
	{
		if (struc_map->map[0][x] == '1'
		&& struc_map->map[struc_map->height - 1][x] == '1')
			x++;
		else
			map_error(struc_map, "Walls error\n");
	}
	while (struc_map->map[y])
	{
		if (struc_map->map[y][0] == '1'
		&& struc_map->map[y][struc_map->width - 1] == '1')
			y++;
		else
			map_error(struc_map, "Walls error\n");
	}
}

void	init_coord_player(t_map *struc_map)
{
	struc_map->player++;
	struc_map->player_x = struc_map->x;
	struc_map->player_y = struc_map->y;
}

void	check_other(t_map *struc_map)
{
	while (struc_map->map[struc_map->y])
	{
		while (struc_map->map[struc_map->y][struc_map->x])
		{
			if (struc_map->map[struc_map->y][struc_map->x] == 'P')
				init_coord_player(struc_map);
			else if (struc_map->map[struc_map->y][struc_map->x] == 'C')
				struc_map->collect++;
			else if (struc_map->map[struc_map->y][struc_map->x] == 'E')
				struc_map->exit++;
			else if (struc_map->map[struc_map->y][struc_map->x] == '1')
				struc_map->walls++;
			else if (struc_map->map[struc_map->y][struc_map->x] == '0')
				struc_map->floor++;
			else
				map_error(struc_map, "Invalid character\n");
			struc_map->x++;
		}
		struc_map->y++;
		struc_map->x = 0;
	}
	if (struc_map->player != 1
		|| struc_map->collect < 1 || struc_map->exit != 1)
		map_error(struc_map, "Invalid count of characters\n");
}

t_map	*check_valid_map(char **map)
{
	t_map	*struc_map;

	struc_map = malloc(sizeof(t_map));
	init_vars(struc_map, map);
	check_hw(struc_map);
	check_walls(struc_map);
	check_other(struc_map);
	return (struc_map);
}
