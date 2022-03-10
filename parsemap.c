/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez <snunez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:38:11 by snunez            #+#    #+#             */
/*   Updated: 2022/03/10 14:03:26 by snunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_ones(char *str)
{
	bool yes;
	int i;

	i = 0;
	if(!str)
		return (-1);
	while(str[i])
	{
		if(str[i] != '1')
			return (-1);
		i++;
	}
	return (1);
}

t_map *read_map(int fd, char *file, t_map *map)
{
	int i;
	int result;
	char *line;
	bool check;

	result = get_next_line(fd, &line);
	check = check_ones(line);
	while(result == 1 && check == true)
	{
		i = 1;
		if(line[0] != '1')
				return ;
		while(str[i])
		{
			if(line[i] == 'C')
				map->items++;
			else if(line[i] == 'P')
				map->pj++;
			else if(line[i] == 'E')
				map->exit++;
			i++;
		}
		free(line);
		result = ft_get_next_line(fd, &line);
	}
	check = check_ones(line);
	free(line);
	close(fd);
	if(result == 0 && check == true && map->pj == 1 && map->items >= 1 && map->exit == 1)
		return(map);
	else
		return NULL;
}
