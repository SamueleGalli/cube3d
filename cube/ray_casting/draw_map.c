/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:34:17 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/08 15:01:52 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head_cube/cube.h"

void	map_raycasting(t_general *g, int i, int j)
{
	if (g->cubed[i][j] == '0')
	{
		printf("pavimento\n");
		//draw_floor(g);
	}
	else if (g->cubed[i][j] == '1')
	{
		printf("muro\n");
		//draw_wall(g);
	}
	if (g->cubed[i][j] == 'N')
		printf("buono\n");
}

void	draw_map(t_general *g)
{
	int	x_p;
	int	y_p;

	x_p = g->x_p;
	y_p = g->y_p;
	g->x = 0;
	g->y = 0;
	while (g->cubed[x_p] != 0)
	{
		while (g->cubed[x_p][y_p] != 0)
		{
			map_raycasting(g, x_p, y_p);
			y_p++;
		}
		y_p = 0;
		x_p++;
	}
}
