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

t_map *save_map(int fd, t_map *map)
{
	int i;
	int result;
	
	i = 0;
	map->map = (char **)malloc((map->height + 1)* sizeof(char *));
	map->map[map->height] = 0;
	result = get_next_line(fd, &map->map[i]);
	i++;
	while(result == 1)
	{
		result = get_next_line(fd, &map->map[i]);
		i++;
	}
	close(fd);
	if(result == 0)
		return(map);
	else
		return (NULL);
}

t_map *read_map(int fd, t_map *map)
{
	int j;
	int result;
	char *line;
	int check;
	/* gestionar errores gnl*/
	line = NULL;
	result = get_next_line(fd, &line);
	map->width = ft_strlen(line);
	check = check_ones(line);
	while(result == 1 && check == 1)
	{
		j = 1;
		map->height++;
		if(line[0] != '1' || line[ft_strlen(line) - 1] != '1' || ft_strlen(line) != map->width)
			return NULL;
		while(line[j])
		{
			check_map(line[j], map);
			j++;
		}
		free(line);
		result = get_next_line(fd, &line);
	}
	if (result == 0){
		map->height++;

	}
	check = check_ones(line);
	free(line);
	close(fd);
	if(result == 0 && check == 1 && map->pj == 1 && map->items >= 1 && map->exit == 1)
		return(map);
	else
		return NULL;
		/* TODO: FREE **MAP */
}
