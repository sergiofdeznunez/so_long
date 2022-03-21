/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez <snunez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:38:11 by snunez            #+#    #+#             */
/*   Updated: 2022/03/21 13:50:40 by snunez           ###   ########.fr       */
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


t_map *read_map(int fd, char *file, t_map *map)
{
	int i;
	int result;
	char *line;
	int check;

	result = get_next_line(fd, &line);
	check = check_ones(line);
	while(result == 1 && check == 1)
	{
		i = 1;
		if(line[0] != '1' || line[ft_strlen(line)] != '1')
				return NULL;
		while(line[i])
		{
			check_map(*(line + i), map);
			i++;
		}
		free(line);
		result = get_next_line(fd, &line);
	}
	check = check_ones(line);
	free(line);
	close(fd);
	if(result == 0 && check == 1 && map->pj == 1 && map->items >= 1 && map->exit == 1)
		return(map);
	else
		return NULL;
}
