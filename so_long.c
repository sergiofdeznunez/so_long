/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez <snunez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:20:48 by snunez            #+#    #+#             */
/*   Updated: 2022/03/10 14:02:51 by snunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int main(int argc, char **argv)
{
	int fd;
	if(argc == 2)
	{
	/*
	 *check exists y .ber [X]
	*/
	char *srch;

	srch = ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]));
	if(ft_strnstr(srch, ".ber", ft_strlen(srch)) || srch == NULL)
		return /*error*/;
	fd = open(argv[1]);
	
	/*
	 * initialize structs[X]
	 * read the map and check if is valid [V]
	*/
	
	/*
	 * game() -> no win sin items, walls, print moves, clean close window , ...
	*/
	}

	void *wdw;
	void *mlx;
	
	mlx = mlx_init();
	wdw = mlx_new_window(wdw, 1000, 1000, "so_long");
	mlx_loop(mlx);
	return 0;
}