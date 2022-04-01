/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez <snunez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:25:21 by snunez            #+#    #+#             */
/*   Updated: 2022/04/01 13:50:57 by snunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "Libft/libft.h"
//# include <mlx.h>
# include "minilibx_linux/mlx.h"

//# linux
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
//# MacOS
//# define KEY_ESC 53
//# define KEY_W 13
//# define KEY_A 0
//# define KEY_S 1
//# define KEY_D 2
//# define KEY_LEFT 123
//# define KEY_UP 126
//# define KEY_RIGHT 124
//# define KEY_DOWN 125

typedef struct s_map
{
	char	**map;
	int		items;
	int		pj;
	int		pj_x;
	int		pj_y;
	int		it_collected;
	int		exit;
	int		width;
	int		height;
}			t_map;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	void	*floor;
	void	*wall;
	void	*pj;
	void	*item;
	void	*exit;
	int		moves;
	void	*map;
}			t_game;

t_map	*read_map(int fd, t_map *map);
t_map	*save_map(int fd, t_map *map);
void	get_images(t_game *game);
void	put_image(char c, t_game *game, size_t i, size_t j);
void	draw_map(t_map *map, t_game *game);
void	initialize_game(t_map *map);
void	move(t_game *game, char dir);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	move_down(t_game *game);
void	move_up(t_game *game);
void	end_game(t_game *game);
void	key_hooks(int key, t_game **game);
#endif