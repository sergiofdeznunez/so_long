/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez <snunez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:20:48 by snunez            #+#    #+#             */
/*   Updated: 2022/03/09 14:25:19 by snunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int main()
{
	/*
	 *check exists y .ber
	*/

	/*
	 * initialize structs
	 * read the map and check if is valid 
	*/
	
	/*
	 * game() -> no win sin items, walls, print moves, clean close window , ...
	*/

	void *wdw;
	void *mlx;
	
	mlx = mlx_init();
	wdw = mlx_new_window(wdw, 1000, 1000, "so_long");
	mlx_loop(mlx);
	return 0;
}