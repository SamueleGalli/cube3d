/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:28:46 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/16 15:13:44 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head_cube/cube.h"

void	initialize_ray(t_general *g, int i)
{
	g->camerax = 2 * i / (double)g->width - 1;
	g->raydirx = g->dirx + g->planex * g->camerax;
	g->raydiry = g->diry + g->planey * g->camerax;
	g->mapx = (int)g->posx;
	g->mapy = (int)g->posy;
	g->deltadistx = fabs(1 / g->raydirx);
	g->deltadisty = fabs(1 / g->raydiry);
	g->hit = 0;
}

void	checking_ray(t_general *g)
{
	if (g->raydirx < 0)
	{
		g->stepx = -1;
		g->sidedistx = (g->posx - g->mapx) * g->deltadistx;
	}
	else
	{
		g->stepx = 1;
		g->sidedistx = (g->mapx + 1.0 - g->posx) * g->deltadistx;
	}
	if (g->raydiry < 0)
	{
		g->stepy = -1;
		g->sidedisty = (g->posy - g->mapy) * g->deltadisty;
	}
	else
	{
		g->stepy = 1;
		g->sidedisty = (g->mapy + 1.0 - g->posy) * g->deltadisty;
	}
}

void	hitting(t_general *g)
{
	while (g->hit == 0)
	{
		if (g->sidedistx < g->sidedisty)
		{
			g->sidedistx += g->deltadistx;
			g->mapx += g->stepx;
			g->side = 0;
		}
		else
		{
			g->sidedisty += g->deltadisty;
			g->mapy += g->stepy;
			g->side = 1;
		}
		if (g->cubed[g->mapy][g->mapx] == '1')
			g->hit = 1;
	}
}

void	distance(t_general *g)
{
	if (g->side == 0)
		g->perpwalldist = (g->mapx - g->posx + \
		(1 - g->stepx) / 2) / g->raydirx;
	else
		g->perpwalldist = (g->mapy - g->posy + \
		(1 - g->stepy) / 2) / g->raydiry;
	g->lineheight = (int)(g->height / g->perpwalldist);
	g->drawstart = -g->lineheight / 2 + g->height / 2;
	if (g->drawstart < 0)
		g->drawstart = 0;
	g->drawend = g->lineheight / 2 + g->height / 2;
	if (g->drawend >= g->height)
		g->drawend = g->height - 1;
}

void	verline(t_general *g, int i)
{
	int	j;

	j = g->drawstart;
	while (j <= g->drawend)
	{
		mlx_pixel_put(g->mlx, g->win, i, j, g->color);
		j++;
	}
}
