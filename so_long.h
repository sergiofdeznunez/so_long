/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez <snunez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:25:21 by snunez            #+#    #+#             */
/*   Updated: 2022/03/22 12:53:08 by snunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
#include <stdio.h>
# include <fcntl.h>
# include "Libft/libft.h"

typedef struct s_map
{
	int items;
	int pj;
	int exit;
}			t_map;

typedef struct s_game
{
	void *window;
	void *mlx;
	t_map *map;
}			t_game;

t_map *read_map(int fd, t_map *map);

#endif