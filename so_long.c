/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez <snunez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:20:48 by snunez            #+#    #+#             */
/*   Updated: 2022/03/22 11:31:39 by snunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void initialize(t_game *game)
{
	game->map = (t_map *)malloc(1 * sizeof(t_map));
	game->map->items = 0;
	game->map->pj = 0;
	game->map->exit = 0;
	game = (t_game *)malloc(1 * sizeof(t_game));
	game->window = NULL;
	game ->mlx = NULL;
	/* IMPORTANT_TODO:  FREE AT ANY TIME */
}

int main(int argc, char **argv)
{
	int fd;
	t_game *game;

	if(argc == 2)
	{
	/**
	 * check exists y .ber [V]
	*/
	if(ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4) != 0)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return(-1);
	/**
	 * initialize structs[X]
	 * read the map and check if is valid [V]
	*/
	initialize(game);
	game->map = read_map(fd, argv[1], game->map);
	if(game->map == NULL)
		return (-1);
	return (0);
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