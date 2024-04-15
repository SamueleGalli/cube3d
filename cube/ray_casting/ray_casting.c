/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:06:44 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/15 15:06:22 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head_cube/cube.h"

void	cont_raycast(t_general *g)
{
	g->ca = fix_angle(g->angle - g->ra);
	g->dish = g->dish * cos(deg_to_rad(g->ca));
	g->lineh = (64 * 320) / g->dish;
	if (g->lineh > 320)
		g->lineh = 320;
	g->lineoff = 160 - (g->lineh >> 1);
	mlx_pixel_put(g->mlx, g->win, g->px, g->py, BLUE);
	mlx_pixel_put(g->mlx, g->win, g->rx, g->ry, GREEN);
	g->ra = (g->ra - 1);
}

void	raycast(t_general *g)
{
	while (g->r < 60)
	{
		g->side = 0;
		vertical_ray(g);
		horizontal_ray(g);
		if (g->disv < g->dish)
		{
			g->rx = g->vx;
			g->ry = g->vy;
			g->dish = g->disv;
		}
		cont_raycast(g);
	}
}
