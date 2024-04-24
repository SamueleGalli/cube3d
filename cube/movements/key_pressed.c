/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:34:00 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/24 12:22:10 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	go_north(t_general *g)
{
	int	x;
	int	y;

	mlx_clear_window(g->mlx, g->win);
	x = (int)(g->posx + g->dirx * g->movespeed);
	y = (int)(g->posy);
	if (g->cubed[y][x] != 0 && g->cubed[y][x] != '1')
		g->posx += g->dirx * g->movespeed;
	x = (int)(g->posx);
	y = (int)(g->posy + g->diry * g->movespeed);
	if (g->cubed[y][x] != 0 && g->cubed[y][x] != '1')
		g->posy += g->diry * g->movespeed;
	update_cube(g);
}

void	go_south(t_general *g)
{
	int	x;
	int	y;

	x = (int)(g->posx - g->dirx * g->movespeed);
	y = (int)(g->posy);
	mlx_clear_window(g->mlx, g->win);
	if (g->cubed[y][x] != 0 && g->cubed[y][x] != '1')
		g->posx -= g->dirx * g->movespeed;
	x = (int)(g->posx);
	y = (int)(g->posy - g->diry * g->movespeed);
	if (g->cubed[y][x] != 0 && g->cubed[y][x] != '1')
		g->posy -= g->diry * g->movespeed;
	update_cube(g);
}

void	go_west(t_general *g)
{
	int	x;
	int	y;

	mlx_clear_window(g->mlx, g->win);
	x = (int)(g->posx - g->planex * g->movespeed);
	y = (int)(g->posy);
	if (g->cubed[y][x] != 0 && g->cubed[y][x] != '1')
		g->posx -= g->planex * g->movespeed;
	x = (int)(g->posx);
	y = (int)(g->posy - g->planey * g->movespeed);
	if (g->cubed[y][x] != 0 && g->cubed[y][x] != '1')
		g->posy -= g->planey * g->movespeed;
	update_cube(g);
}

void	go_east(t_general *g)
{
	int	x;
	int	y;

	mlx_clear_window(g->mlx, g->win);
	x = (int)(g->posx + g->planex * g->movespeed);
	y = (int)(g->posy);
	if (g->cubed[y][x] != 0 && g->cubed[y][x] != '1')
		g->posx += g->planex * g->movespeed;
	x = (int)(g->posx);
	y = (int)(g->posy + g->planey * g->movespeed);
	if (g->cubed[y][x] != 0 && g->cubed[y][x] != '1')
		g->posy += g->planey * g->movespeed;
	update_cube(g);
}
