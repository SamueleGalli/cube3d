/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:59:35 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/15 14:53:01 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head_cube/cube.h"

void	draw_map(t_general *g, int x, int y)
{
	while (y < g->y_end)
	{
		x = 0;
		while (x < g->x_end)
		{
			if (g->cubed[y][x] == '1')
				g->color = WHITE;
			else
				g->color = RED;
			g->xo = x * 64;
			g->yo = y * 64;
			g->i = g->xo - 1;
			g->j = g->yo - 1;
			while (++g->i < g->xo + 64)
			{
				while (++g->j < g->yo + 64)
					mlx_pixel_put(g->mlx, g->win, g->i, g->j, g->color);
			}
			x++;
		}
		y++;
	}
}

int	update_cube(t_general *g)
{
	draw_map(g, 0, 0);
	g->x = 0;
	g->y = 0;
	g->pdx = cos(deg_to_rad(g->angle));
	g->pdy = -sin(deg_to_rad(g->angle));
	g->ra = fix_angle(g->angle + 30);
	g->r = 0;
	raycast(g);
	return (0);
}
