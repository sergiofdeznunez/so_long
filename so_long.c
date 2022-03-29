/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez <snunez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:20:48 by snunez            #+#    #+#             */
/*   Updated: 2022/03/29 14:03:44 by snunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void get_images(t_game *game)
{
	int size;
	char *data[5];

	size = 32;
	data[0] = "./textures/floor.xpm";
	data[1] = "./textures/wall.xpm";
	data[2] = "./textures/avatar.xpm";
	data[3] = "./textures/item.xpm";
	data[4] = "./textures/door.xpm";

	game->floor = mlx_xpm_file_to_image(game->mlx, data[0], &size, &size);
	game->wall = mlx_xpm_file_to_image(game->mlx, data[1], &size, &size);
	game->pj = mlx_xpm_file_to_image(game->mlx, data[2], &size, &size);
	game->item = mlx_xpm_file_to_image(game->mlx, data[3], &size, &size);
	game->exit = mlx_xpm_file_to_image(game->mlx, data[4], &size, &size);
}

void put_image(char c, t_game *game, size_t i, size_t j)
{

	size_t ni;
	size_t nj;

	ni = i * 32;
	nj = j * 32;
	
	mlx_put_image_to_window(game->mlx, game->window, game->floor, ni, nj);

	if(c == '1')
		mlx_put_image_to_window(game->mlx, game->window,  game->wall, ni, nj);
	else if(c == 'P')
		mlx_put_image_to_window(game->mlx, game->window, game->pj, ni, nj);
	else if(c == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->item, ni, nj);
	else if(c == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->exit, ni, nj);
}

void draw_map(t_map *map, t_game *game)
{
	size_t i;
	size_t j;

	i = 0;
	while(map->map[i] && i < map->height)
	{
		j = 0;
		while(map->map[i][j] && j < map->width)
		{
			put_image(map->map[i][j], game, j, i);
			j++;
		}
		i++;
	}
}

void initialize_game(t_map *map)
{
	t_game *game;

	game = (t_game *)malloc(1 * sizeof(t_game));
	ft_bzero(game, sizeof(t_game));
	game->map = map;

	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, (32 * map->width), (32 * map->height), "s");
	get_images(game);
	draw_map(map, game);
	//poner hooks
	mlx_loop(game->mlx);
	
	/* TODO: FREE AT ANY TIME */
}

// void test_map(char **str)
// {
// 	int i = 0;
// 	int j;

// 	while(str[i])
// 	{
// 		j = 0;
// 		while(str[i][j])
// 		{
// 			write(1, &str[i][j], 1);
// 			j++;
// 		}
// 		write(1, "\n", 1);
// 		i++;
// 	}
// }


int main(int argc, char **argv)
{
	int fd;
	t_map	*info_mapa; 

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
		 * initialize structs[V]
		 * read the map and check if is valid [V]
		*/
		info_mapa = (t_map *)malloc(1 * sizeof(t_map)); //error
		ft_bzero(info_mapa, sizeof(t_map));
		info_mapa = read_map(fd, info_mapa);
		fd = open(argv[1], O_RDONLY);
		info_mapa = save_map(fd, info_mapa);
		if(info_mapa->map == NULL)
		{
			printf("invalid map\n");
			return (-1);
		}
		printf("valid map\n");
		//test_map(info_mapa->map);
		/**
		 * game(no win sin items, walls, print moves, clean close window , ...)
		 * 
		*/
		initialize_game(info_mapa);

		return (0);
	}

}