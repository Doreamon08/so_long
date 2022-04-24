/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 13:52:06 by rabbie            #+#    #+#             */
/*   Updated: 2022/04/24 13:21:17 by rabbie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_char(char **temp)
{
	int	i;

	i = 0;
	if (!temp)
		return ;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
}

void	extension(char *map_name)
{
	int		len_map_name;
	int		i;
	char	*ext;

	ext = ".ber";
	i = 0;	
	len_map_name = ft_strlen(map_name);
	if (len_map_name < 5)
		errors("Extension error\n");
	while (i < 4)
	{
		if (map_name[(len_map_name - i) - 1] == ext[(4 - i) - 1])
			i++;
		else
			errors("Extension error\n");
	}
}

char	**unit_char(char **temp_map, char *line)
{
	char	**map;
	int		i;

	i = 0;
	if (temp_map != NULL)
		while (temp_map[i])
			i++;
	map = malloc (sizeof(char *) * (i + 2));
	i = 0;
	if (temp_map != NULL)
	{
		while (temp_map[i])
		{
			map[i] = temp_map[i];
			i++;
		}
	}
	map[i] = line;
	map[i + 1] = NULL;
	free(temp_map);
	return (map);
}

void	map_printer(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
		j = 0;
	}
}

t_map	*map(char *map_name, int av)
{
	int		fd;
	char	**map;
	char	*line;
	t_map	*struc_map;

	map = NULL;
	if (av == 1 || av < 2)
		errors("invalid count of arguments\n");
	extension(map_name);
	fd = open(map_name, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		map = unit_char(map, line);
		line = get_next_line(fd);
	}
	struc_map = check_valid_map(map);
	close(fd);
	return (struc_map);
}
