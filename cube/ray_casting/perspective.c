/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:06:44 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/12 16:10:30 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head_cube/cube.h"

void	draw_walls(t_general *g, int x, int y, int distance)
{
	int	w_height;
	int	w_top;
	int	w_bottom;
	int	color;

	if (distance <= 0)
	{
		color = WHITE;
		w_height = g->height;
	}
	else
	{
		color = CYAN;
		w_height = (int)(g->height / distance);
	}
	w_top = (g->height - w_height) / 2;
	w_bottom = w_top + w_height;
	if (y >= w_top && y < w_bottom)
		mlx_pixel_put(g->mlx, g->win, x, y, color);
}

void	draw_floor(t_general *g, int x, int y, int distance)
{
	int	f_height;
	int	f_top;
	int	f_bottom;
	int	color;


	if (distance <= 0)
	{
		color = RED;
		f_height = g->height;
	}
	else
	{
		color = BLUE;
		f_height = (int)(g->height / distance);
	}
	f_top = (g->height - f_height) / 2;
	f_bottom = f_top + f_height;
	if (y >= f_top && y < f_bottom)
		mlx_pixel_put(g->mlx, g->win, x, y, color);
}

void	draw_ceiling(t_general *g, int x, int y, int distance)
{
	int	c_height;
	int	c_top;
	int	c_bottom;
	int	color;

	if (distance <= 0)
	{
		color = YELLOW;
		c_height = g->height;
	}
	else
	{
		color = GREEN;
		c_height = (int)(g->height / distance);
	}
	c_top = (g->height - g->y_p) / 2;
	c_bottom = c_top + c_height;
	if (y >= c_top && y < c_bottom)
		mlx_pixel_put(g->mlx, g->win, x, y, color);
}
