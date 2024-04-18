/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:22:38 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/18 18:24:17 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"
/*dirx y direzione della telecameta
planex y manipola la direzione dello
visuale in prospettivo col piano*/

void	move_direction(char c, t_general *g)
{
	if (c == 'S')
		go_south(g);
	else if (c == 'W')
		go_north(g);
	else if (c == 'A')
		go_west(g);
	else if (c == 'D')
		go_east(g);
}

void	go_right(t_general *g)
{
	double	oldirx;
	double	oldplanex;

	mlx_clear_window(g->mlx, g->win);
	oldplanex = g->planex;
	oldirx = g->dirx;
	g->dirx = g->dirx * cos(-g->rotspeed) - g->diry * sin(-g->rotspeed);
	g->diry = oldirx * sin(-g->rotspeed) + g->diry * cos(-g->rotspeed);
	g->planex = g->planex * cos(-g->rotspeed) - g->planey * sin(-g->rotspeed);
	g->planey = oldplanex * sin(-g->rotspeed) + g->planey * cos(-g->rotspeed);
	update_cube(g);
}

void	go_left(t_general *g)
{
	double	oldirx;
	double	oldplanex;

	oldplanex = g->planex;
	oldirx = g->dirx;
	mlx_clear_window(g->mlx, g->win);
	g->dirx = g->dirx * cos(g->rotspeed) - g->diry * sin(g->rotspeed);
	g->diry = oldirx * sin(g->rotspeed) + g->diry * cos(g->rotspeed);
	g->planex = g->planex * cos(g->rotspeed) - g->planey * sin(g->rotspeed);
	g->planey = oldplanex * sin(g->rotspeed) + g->planey * cos(g->rotspeed);
	update_cube(g);
}

void	rotate(t_general *g, int key)
{
	if (key == 65361)
		go_right(g);
	else if (key == 65363)
		go_left(g);
}

int	manage_key(int key, t_general *g)
{
	if (key == ESC)
		end_program(g);
	if (key == A)
		move_direction('A', g);
	else if (key == W)
		move_direction('W', g);
	else if (key == D)
		move_direction('D', g);
	else if (key == S)
		move_direction('S', g);
	else if (key == 65361 || key == 65363)
		rotate(g, key);
	return (1);
}
