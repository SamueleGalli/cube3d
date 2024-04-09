/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:59:35 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/09 15:07:44 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head_cube/cube.h"

void	fov2(t_general *g)
{
	int	max_x;
	int	max_y;
	int	hit;

	hit = 0;
	if (g->fov == 0 || g->fov == g->pg)
	{
		g->ray_x = g->x_p;
		g->ray_y = g->y_p;
	}
	while (hit < 8)
	{
		max_x = (int)(g->ray_x) >> 6;
		max_y = (int)(g->ray_y) >> 6;
	}
}

void	fov(t_general *g)
{
	float	t;

	t = -1 / tan(g->fov);
	g->ray_y = 0;
	g->ray_x = 0;
	if (g->fov > g->pg)
	{
		g->ray_x = (((int)g->y_p >> 6) << 6) - 0.0001;
		g->ray_y = (g->y_p - g->ray_y) * t + g->x_p;
		g->x_orizontal = -g->y_orizontal * t;
	}
	if (g->fov < g->pg)
	{
		g->ray_x = (((int)g->y_p >> 6) << 6) + 64;
		g->x_orizontal = 64;
		g->ray_y = (g->y_p - g->ray_y) * t + g->x_p;
		g->x_orizontal = -g->y_orizontal * t;
	}
	fov2(g);
}
