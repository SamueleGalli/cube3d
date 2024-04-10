/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:34:17 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/10 15:47:24 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head_cube/cube.h"

void	drawing(t_general *g, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < g->size_obj)
	{
		j = 0;
		while (j < g->size_obj)
		{
			mlx_pixel_put(g->mlx, g->win, g->x * g->size_obj + i, \
				g->y * g->size_obj + j, color);
			j++;
		}
		i++;
	}
}

void	map_raycasting(t_general *g)
{
	if (g->cubed[g->y][g->x] == '0')
		drawing(g, 0xFF0000FF);
	else if (g->cubed[g->y][g->x] == '1')
		drawing(g, 0x0000F000);
	if (g->cubed[g->y][g->x] == 'N' || g->cubed[g->y][g->x] == 'S' ||
		g->cubed[g->y][g->x] == 'E' || g->cubed[g->y][g->x] == 'W')
		drawing(g, 0x0FF0FFF0);
}

void	draw_map(t_general *g)
{
	g->x = 0;
	g->y = 0;
	while (g->cubed[g->y] != 0)
	{
		while (g->cubed[g->y][g->x] != 0)
		{
			map_raycasting(g);
			g->x++;
		}
		g->x = 0;
		g->y++;
	}
	raycast(g, 0, 0);
}

int	update_cube(t_general *g)
{
	draw_map(g);
	return (0);
}
