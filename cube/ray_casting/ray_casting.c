/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:59:35 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/11 14:45:50 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head_cube/cube.h"

double	angle_view(t_general *g)
{
	if (g->p_view == 'N')
		return (3 * PG / 2);
	else if (g->p_view == 'E')
		return (0);
	else if (g->p_view == 'S')
		return (PG / 2);
	else if (g->p_view == 'W')
		return (PG);
	return (1);
}

double	raycast_distance(t_general *g, double angle, int mx, int my)
{
	double	x;
	double	y;
	double	dx;
	double	dy;

	x = g->x_p;
	y = g->y_p;
	dx = cos(angle);
	dy = sin(angle);
	while (x >= 0 && x < g->x_end * g->size_obj && y >= 0 && \
	y < g->y_end * g->size_obj)
	{
		mx = (int)(x + g->size_obj);
		my = (int)(y + g->size_obj);
		if (mx >= 0 && mx < g->x_end && my >= 0 && my < g->y_end && \
			g->cubed[my][mx] == '1')
			return (sqrt((x - g->x_p) * (x - g->x_p) + \
			(y - g->y_p) * (y - g->y_p)));
		x += dx;
		y += dy;
	}
	return (0);
}

void	angle_and_draw(t_general *g, int x, int y)
{
	double	distance;
	double	angle;

	angle = atan2(y - g->y_p, x - g->x_p) - angle_view(g);
	distance = raycast_distance(g, angle, 0, 0);
	draw_walls(g, x, y, distance);
	draw_floor(g, x, y, distance);
	draw_ceiling(g, x, y, distance);
}

void	raycast(t_general *g)
{
	int		y;
	int		x;	

	y = 0;
	while (y < g->height)
	{
		x = 0;
		while (x < g->width)
		{
			angle_and_draw(g, x, y);
			x++;
		}
		y++;
	}
}

int	update_cube(t_general *g)
{
	g->x = 0;
	g->y = 0;
	raycast(g);
	return (0);
}
