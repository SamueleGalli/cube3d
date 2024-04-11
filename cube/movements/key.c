/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:22:38 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/11 14:56:04 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head_cube/cube.h"

void	move_direction(char c, t_general *g)
{
	if (c == 'S' && g->cubed[g->pl_y + 1][g->pl_x] != '1')
	{
		g->cubed[g->pl_y + 1][g->pl_x] = g->cubed[g->pl_y][g->pl_x];
		g->cubed[g->pl_y][g->pl_x] = '0';
		g->y_p += g->size_obj;
	}
	else if (c == 'W' && g->cubed[g->pl_y - 1][g->pl_x] != '1')
	{
		g->cubed[g->pl_y - 1][g->pl_x] = g->cubed[g->pl_y][g->pl_x];
		g->cubed[g->pl_y][g->pl_x] = '0';
		g->y_p -= g->size_obj;
	}
	else if (c == 'A' && g->cubed[g->pl_y][g->pl_x - 1] != '1')
	{
		g->cubed[g->pl_y][g->pl_x - 1] = g->cubed[g->pl_y][g->pl_x];
		g->cubed[g->pl_y][g->pl_x] = '0';
		g->x_p -= g->size_obj;
	}
	else if (c == 'D' && g->cubed[g->pl_y][g->pl_x + 1] != '1')
	{
		g->cubed[g->pl_y][g->pl_x + 1] = g->cubed[g->pl_y][g->pl_x];
		g->cubed[g->pl_y][g->pl_x] = '0';
		g->x_p += g->size_obj;
	}
	mlx_clear_window(g->mlx, g->win);
}

void	rotate(t_general *g, int key)
{
	if (key == 65361)
	{
		g->angle += 0.1;
		if (g->angle >= 2 * PG)
			g->angle -= 2 * PG;
	}
	else
	{
		g->angle -= 0.1;
		if (g->angle < 0)
			g->angle += 2 * PG;
	}
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
