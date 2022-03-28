/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez <snunez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:20:48 by snunez            #+#    #+#             */
/*   Updated: 2022/03/28 14:43:40 by snunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


//void get_images(t_game *game)
//{
//	int size = 32;
//	game->floor = mlx_xpm_file_to_image(game->mlx, "./textures/floor.xpm", &size, &size);
//	game->wall = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm", &game->img_width, &game->img_height);
//	game->pj = mlx_xpm_file_to_image(game->mlx, "./textures/avatar.xpm", &game->img_width, &game->img_height);
//	game->item = mlx_xpm_file_to_image(game->mlx, "./textures/item.xpm", &game->img_width, &game->img_height);
//	game->exit = mlx_xpm_file_to_image(game->mlx, "./textures/door.xpm", &game->img_width, &game->img_height);
//}

void initialize_game(t_map *map)
{
	t_game *game;

	game = (t_game *)malloc(1 * sizeof(t_game));
	ft_bzero(game, sizeof(t_game));
	game->map = map;

	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, (32 * map->width), 32 * map->height, "s");
	//get_images(game);
	//pintar mapa
	//poner hooks
	//mlx_loop(game->mlx);
	
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
	t_map	*infoMapa; 

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
		infoMapa = (t_map *)malloc(1 * sizeof(t_map)); //error
		ft_bzero(infoMapa, sizeof(t_map));
		infoMapa = read_map(fd, infoMapa);
		fd = open(argv[1], O_RDONLY);
		infoMapa = save_map(fd, infoMapa);
		if(infoMapa->map == NULL)
		{
			printf("invalid map\n");
			return (-1);
		}
		printf("valid map\n");
		//test_map(infoMapa->map);
		/**
		 * game(no win sin items, walls, print moves, clean close window , ...)
		 * 
		*/
		initialize_game(infoMapa);

		return (0);
	}

}