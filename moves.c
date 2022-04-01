/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez <snunez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:10:58 by snunez            #+#    #+#             */
/*   Updated: 2022/04/01 13:26:48 by snunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_game *game, char dir)
{
	t_map	*map;

	map = game->map;
	if (dir == 'l')
		map->pj_x--;
	if (dir == 'r')
		map->pj_x++;
	if (dir == 'u')
		map->pj_y--;
	if (dir == 'd')
		map->pj_y++;
	mlx_clear_window(game->mlx, game->window);
	draw_map(map, game);
	
	/*Print moves and more to do*/
}

void	move_left(t_game *game)
{
	t_map	*map;

	map = game->map;
	if (map->map[map->pj_y][map->pj_x - 1] == '0')
		move(game, 'l');
	else if (map->map[map->pj_y][map->pj_x - 1] == 'C')
	{
		map->map[map->pj_y][map->pj_x - 1] = '0';
		move(game, 'l');
		map->it_collected++;
	}
	else if (map->map[map->pj_y][map->pj_x - 1] == 'E')
		if (map->it_collected == map->items)
			end_game(game);
}

void	move_right(t_game *game)
{
	t_map	*map;

	map = game->map;
	if (map->map[map->pj_y][map->pj_x + 1] == '0')
		move(game, 'r');
	else if (map->map[map->pj_y][map->pj_x + 1] == 'C')
	{
		map->map[map->pj_y][map->pj_x + 1] = '0';
		move(game, 'r');
		map->it_collected++;
	}
	else if (map->map[map->pj_y][map->pj_x + 1] == 'E')
		if (map->it_collected == map->items)
			end_game(game);
}

void	move_down(t_game *game)
{
	t_map	*map;

	map = game->map;
	if (map->map[map->pj_y + 1][map->pj_x] == '0')
		move(game, 'd');
	else if (map->map[map->pj_y + 1][map->pj_x] == 'C')
	{
		map->map[map->pj_y + 1][map->pj_x] = '0';
		move(game, 'd');
		map->it_collected++;
	}
	else if (map->map[map->pj_y + 1][map->pj_x] == 'E')
		if (map->it_collected == map->items)
			end_game(game);
}

void	move_up(t_game *game)
{
	t_map	*map;

	map = game->map;
	if (map->map[map->pj_y - 1][map->pj_x] == '0')
		move(game, 'u');
	else if (map->map[map->pj_y - 1][map->pj_x] == 'C')
	{
		map->map[map->pj_y - 1][map->pj_x] = '0';
		move(game, 'u');
		map->it_collected++;
	}
	else if (map->map[map->pj_y - 1][map->pj_x] == 'E')
		if (map->it_collected == map->items)
			end_game(game);
}
