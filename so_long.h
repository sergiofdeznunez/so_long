/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez <snunez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:25:21 by snunez            #+#    #+#             */
/*   Updated: 2022/03/29 13:46:25 by snunez           ###   ########.fr       */
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


typedef struct s_map
{
	char **map;
	int items;
	int pj;
	int exit;
	int width; //ancho
	int height; //alto
}			t_map;

typedef struct s_game
{
	void *mlx;
	void *window;
	void *floor;
	void *wall;
	void *pj;
	void *item;
	void *exit;
	void *map;
}			t_game;

t_map *read_map(int fd, t_map *map);
t_map *save_map(int fd, t_map *map);
void get_images(t_game *game);
void put_image(char c, t_game *game, size_t i, size_t j);
void draw_map(t_map *map, t_game *game);
void initialize_game(t_map *map);
#endif