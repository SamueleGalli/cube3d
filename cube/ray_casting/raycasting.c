/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:28:46 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/18 18:24:17 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

/*
(camerax) centra player nella mappa
(dirx, diry) direzione player N/W/S/E
(mapx, mapy) posizone player
(deltadistx, deltadisty) distanza del raggio dal muro
(hit) variabile 1/0
*/
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

/*
calcola distanza del raggio
(raydirx < 0) va verso sinistra
altrimenti verso destra
(raydiry <0) va giu
altrimenti va su
(stepx e stepy) indicano come si muove il raggio
(sidestepx e sidestepy) indicano la distanza tra il punto corrente
e la sua cella successiva
*/
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

/*
traccia un raggio cercando 
il muro di in cella
l'if else indica dove si muove il raggio
*/
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
/*
l'if else indica se a colpito un 
raggio l'ungo l'asse x o y
(lineheight) indica la altezza muro
(drawstart) indica il punto in cui
devi iniziare a disegnare il muro
(drawend) indica il punto in cui finisce il
disegnamento del muro 
*/

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

/*
disenga un pixel alla volta partendo da drawstart
fino a drawend del colore definito in g->color
verticalmente sullo schermo
*/
void	verline(t_general *g, int i)
{
	while (g->drawstart <= g->drawend)
	{
		mlx_pixel_put(g->mlx, g->win, i, g->drawstart, g->color);
		g->drawstart++;
	}
}
