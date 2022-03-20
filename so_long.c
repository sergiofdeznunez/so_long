/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez <snunez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:20:48 by snunez            #+#    #+#             */
/*   Updated: 2022/03/16 14:07:14 by snunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>


int main(int argc, char **argv)
{
	int fd;
	t_map *map;
	t_game *game;

	if(argc == 2)
	{
	/**
	 * check exists y .ber [V]
	*/
	if(ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4) != 0)
		return /*(error)*/;
	fd = open(argv[1]);

	/*check */

	/**
	 * initialize structs[X]
	 * read the map and check if is valid [V]
	*/
	initialize_structs(&game, &map);
	game->map = read_map(fd, argv[1], &map);
	if(game->map == NULL)
		return /*(error)*/;

	/**
	 * game() -> no win sin items, walls, print moves, clean close window , ...
	*/
	}

	//void *wdw;
	//void *mlx;
	//
	//mlx = mlx_init();
	//wdw = mlx_new_window(wdw, 1000, 1000, "so_long");
	//mlx_loop(mlx);
	//return 0;
}