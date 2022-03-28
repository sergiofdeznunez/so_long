/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez <snunez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:38:11 by snunez            #+#    #+#             */
/*   Updated: 2022/03/28 12:27:06 by snunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_ones(char *line)
{
	int i;

	i = 0;
	if(!line)
		return (-1);
	while(line[i])
	{
		if(line[i] != '1')
			return (-1);
		i++;
	}
	return (1);
}

void check_map(char char_map, t_map *map)
{

	if(!char_map || map == NULL)
		return ;
	if(char_map == 'C')
		map->items++;
	if(char_map == 'P')
		map->pj++;
	if(char_map == 'E')
		map->exit++;
}


t_map *read_map(int fd, t_map *map)
{
	int i;
	int j;
	int result;
	int check;
	
	i = 0;
	result = get_next_line(fd, map->map);
	check = check_ones(map->map[i]);
	while(result == 1 && check == 1)
	{
		j = 1;
		if(map->map[i][0] != '1' || map->map[i][ft_strlen(map->map[i]) - 1] != '1')
			return NULL;
		while(map->map[i][j])
		{
			check_map(map->map[i][j], map);
			j++;
		}
		result = get_next_line(fd, map->map);
		i++;
	}
	check = check_ones(map->map[i]);
	close(fd);
	if(result == 0 && check == 1 && map->pj == 1 && map->items >= 1 && map->exit == 1)
		return(map);
	else
		return NULL;
		/* TODO: FREE **MAP */
}
