/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orizontal_vertical_ray.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:03:38 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/15 15:06:42 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head_cube/cube.h"

void	cont_horizontal_ray(t_general *g)
{
	while (g->dof < 8)
	{
		g->mx = (int)(g->rx) >> 6;
		g->my = (int)(g->ry) >> 6;
		g->mp = g->my * g->x_end + g->mx;
		if (g->mp > 0 && g->mp < g->x_end * g->y_end
			&& g->cubed[g->my][g->mx] == '1')
		{
			g->dof = 8;
			g->dish = cos(deg_to_rad(g->ra) * (g->rx - g->px) - \
			sin(deg_to_rad(g->ra)) * (g->ry - g->py));
		}
		else
		{
			g->rx += g->xo;
			g->ry += g->yo;
			g->dof++;
		}
	}
}

void	horizontal_ray(t_general *g)
{
	g->dof = 0;
	g->dish = 100000;
	g->tan = 1.0 / g->tan;
	if (sin(deg_to_rad(g->ra)) > 0.001)
	{
		g->ry = (((int)g->py >> 6) << 6) - 0.0001;
		g->rx = (g->py - g->ry) * g->tan + g->px;
		g->yo = -64;
		g->xo = -g->yo * g->tan;
	}
	else if (sin(deg_to_rad(g->ra)) < -0.001)
	{
		g->ry = (((int)g->py >> 6) << 6) + 64;
		g->rx = (g->py - g->ry) * g->tan + g->px;
		g->yo = 64;
		g->xo = -g->yo * g->tan;
	}
	else
	{
		g->rx = g->px;
		g->ry = g->py;
		g->dof = 8;
	}
	cont_horizontal_ray(g);
}

void	cont_vertical_ray(t_general *g)
{
	while (g->dof < 8)
	{
		g->mx = (int)(g->rx) >> 6;
		g->my = (int)(g->ry) >> 6;
		g->mp = g->my * g->x_end + g->mx;
		if (g->mp > 0 && g->mp < g->x_end * g->y_end && \
			g->cubed[g->my][g->mx] == '1')
		{
			g->dof = 8;
			g->disv = cos(deg_to_rad(g->ra)) * (g->rx - g->px) - \
			sin(deg_to_rad(g->ra)) * (g->ry - g->py);
		}
		else
		{
			g->rx += g->xo;
			g->ry += g->yo;
			g->dof++;
		}
		g->vx = g->rx;
		g->vy = g->ry;
	}
}

void	vertical_ray(t_general *g)
{
	g->dof = 0;
	g->disv = 100000;
	g->tan = tan(deg_to_rad(g->ra));
	if (cos(deg_to_rad(g->ra)) > 0.001)
	{
		g->rx = (((int)g->px >> 6) << 6) + 64;
		g->ry = (g->px - g->rx) * g->tan + g->py;
		g->xo = 64;
		g->yo = -g->xo * g->tan;
	}
	else if (cos(deg_to_rad(g->ra)) < -0.001)
	{
		g->rx = (((int)g->px >> 6) << 6) - 0.0001;
		g->ry = (g->px - g->rx) * g->tan + g->py;
		g->xo = -64;
		g->yo = -g->xo * g->tan;
	}
	else
	{
		g->rx = g->px;
		g->ry = g->py;
		g->dof = 8;
	}
	cont_vertical_ray(g);
}
