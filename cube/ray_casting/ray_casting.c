/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:59:35 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/10 15:47:10 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head_cube/cube.h"

void	draw_wall(t_general *g, double ray)
{
	double	wall_x;
	double	wall_y;

	wall_x = g->px_size + cos(ray) * g->size_obj;
	wall_y = g->py_size + sin(ray) * g->size_obj;
	mlx_pixel_put(g->mlx, g->win, wall_x, wall_y, 0xFF0000);
}

double	angle_view(t_general *g)
{
	if (g->p_view == 'N')
		return (g->pg / 2);
	else if (g->p_view == 'E')
		return (0);
	else if (g->p_view == 'S')
		return (g->pg / 2);
	else if (g->p_view == 'W')
		return (g->pg);
	return (1);
}

double	raycast_distance(t_general *g, double angle, int mx, int my)
{
	double	x;
	double	y;
	double	dx;
	double	dy;

	x = g->px_size;
	y = g->py_size;
	dx = cos(angle);
	dy = sin(angle);
	while (x >= 0 && x < g->x_end * g->size_obj && y >= 0 && \
	y < g->y_end * g->size_obj)
	{
		mx = (int)(x / g->size_obj);
		my = (int)(y / g->size_obj);
		if (mx >= 0 && mx < g->x_end && my >= 0 && my < g->y_end && \
		g->cubed[my][mx] == '1')
			return (sqrt((x - g->px_size) * \
			(x - g->px_size) + (y - g->py_size) * (y - g->py_size)));
		x += dx;
		y += dy;
	}
	return (0);
}

void	draw_columns(t_general *g, int x, int distance)
{
	int	c_height;
	int	color;
	int	start_y;
	int	y;

	if (distance != 0)
		c_height = (int)(g->height / distance);
	else
		c_height = g->height;
	color = 0xFF0000;
	start_y = (g->height - c_height) / 2;
	y = start_y;
	while (y < start_y + c_height)
	{
		mlx_pixel_put(g->mlx, g->win, x * g->size_obj + g->size_obj / 2, \
		y, color);
		y++;
	}
}

void	raycast(t_general *g, int s_x, int s_y)
{
	int		y;
	int		x;
	double	angle;
	double	distance;

	y = 0;
	x = 0;
	while (y < g->y_end)
	{
		while (x < g->x_end)
		{
			s_x = x * g->size_obj + g->size_obj / 2;
			s_y = y * g->size_obj + g->size_obj / 2;
			angle = (atan2(s_y - g->py_size, s_x - g->px_size)) - angle_view(g);
			distance = raycast_distance(g, angle, 0, 0);
			draw_columns(g, x, distance);
			x++;
		}
		y++;
	}
}
