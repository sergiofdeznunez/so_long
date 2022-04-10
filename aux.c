/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez <snunez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:04:57 by snunez            #+#    #+#             */
/*   Updated: 2022/04/10 17:39:08 by snunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_game(t_game *game)
{
	t_map	*map;

	map = (t_map *)game->map;
	mlx_clear_window(game->mlx, game->window);
	mlx_destroy_window(game->mlx, game->window);
	ft_free_double_pointer((void **)map->map);
	free(map);
	free(game);
	exit(EXIT_SUCCESS);
}

void	close_window(t_game *game)
{
	(void)game;
	exit(EXIT_SUCCESS);
}

void	ft_exit(t_map **map)
{
	printf("Error: not a valid map\n");
	free(*map);
	exit(1);
}

void	ft_exit_free(t_map *map)
{
	printf("Error with the map, freeing ...\n");
	ft_free_double_pointer((void **)map->map);
	free(map);
	exit(1);
}

void	key_hooks(int key, t_game **game)
{
	if (key == KEY_ESC)
		end_game(*game);
	else if (key == KEY_W || key == KEY_UP)
		move_up(*game);
	else if (key == KEY_A || key == KEY_LEFT)
		move_left(*game);
	else if (key == KEY_S || key == KEY_DOWN)
		move_down(*game);
	else if (key == KEY_D || key == KEY_RIGHT)
		move_right(*game);
}
