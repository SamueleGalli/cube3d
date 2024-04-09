/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:34:17 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/09 13:01:22 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head_cube/cube.h"

void	map_raycasting(t_general *g)
{
	int	i;

	i = 0;
	if (g->cubed[g->y][g->x] == '0')
	{
		//printf("pavimento\n");
		while (i < 20)
		{
			mlx_pixel_put(g->mlx, g->win, g->x * 60 + i, g->y * 60 + i, 0x00FF0000);
			i++;
		}
		//draw_floor(g);
	}
	else if (g->cubed[g->y][g->x] == '1')
	{
		while (i < 20)
		{
			mlx_pixel_put(g->mlx, g->win, g->x * 60 + i, g->y * 60 + i, 0x0000F000);
			i++;
		}
		//printf("muro\n");
		//draw_wall(g);
	}
	if (g->cubed[g->y][g->x] == 'N' || g->cubed[g->y][g->x] == 'S' || \
		g->cubed[g->y][g->x] == 'E' || g->cubed[g->y][g->x] == 'W')
	{
		while (i < 20)
		{
			mlx_pixel_put(g->mlx, g->win, g->x * 60 + i, g->y * 60 + i, 0xFF0F0FF);
			i++;
		}
		//printf("buono\n");
	}
}

int	draw_map(t_general *g)
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
	return (0);
}
