/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:30:51 by rabbie            #+#    #+#             */
/*   Updated: 2022/04/27 20:06:15 by rabbie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write (fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (fd < 0)
		return ;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = num * -1;
	}
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd);
	ft_putchar_fd((num % 10) + '0', fd);
}

void	init_vars(t_map *struc_map, char **map)
{
	struc_map->map = map;
	struc_map->player = 0;
	struc_map->player_x = 0;
	struc_map->player_y = 0;
	struc_map->collect = 0;
	struc_map->exit = 0;
	struc_map->height = 0;
	struc_map->width = 0;
	struc_map->y = 0;
	struc_map->x = 0;
}
