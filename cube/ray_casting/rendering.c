/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:59:35 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/18 18:24:17 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

/*
resetta buffer di immagine
*/
void	rebuf_calc(t_general *g)
{
	if (g->rebuf == 1)
	{
		g->x = 0;
		while (g->x < g->height)
		{
			g->y = 0;
			while (g->y < g->width)
				g->buf[g->x][g->y++] = 0;
			g->x++;
		}
		g->rebuf = 0;
	}
}
/*
associa il buffer all'immagine per disegnarla su schermata
*/

void	draw(t_general *g)
{
	g->y = 0;
	while (g->y < g->height)
	{
		g->x = 0;
		while (g->x < g->width)
		{
			g->data[g->y * g->width + g->x] = g->buf[g->y][g->x];
			g->x++;
		}
		g->y++;
	}
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
}

int	update_cube(t_general *g)
{
	int	x;

	x = 0;
	rebuf_calc(g);
	while (x < g->width)
	{
		initialize_ray(g, x);
		checking_ray(g);
		hitting(g);
		distance(g);
		painting(g, x);
		x++;
	}
	draw(g);
	return (0);
}
