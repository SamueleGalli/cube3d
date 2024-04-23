/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_and_ceiling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:22:32 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/23 14:56:28 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"
/*
disegna fino all'altezza dello schermo
(g->currentdist) distanza dal piano del pavimento
(g->weight) spessore pavimento
(g->currentfloorx, g->currentfloory) distanza tra muro e pavimento
(g->floortexx, g->floortexy) cordinate texture
(g->checkerboardpattern)
*/

void	floor_cont_casting(t_general *g, int y, int x)
{
	while (y < g->height)
	{
		g->currentdist = g->height / (2.0 * y - g->height);
		g->weight = (g->currentdist - g->distplayer) / \
		(g->distwall - g->distplayer);
		g->currentfloorx = g->weight * g->floorxwall + \
		(1.0 - g->weight) * g->posx;
		g->currentfloory = g->weight * g->floorywall + \
		(1.0 - g->weight) * g->posy;
		g->floortexx = (int)(g->currentfloorx * g->img_width) % g->img_width;
		g->floortexy = (int)(g->currentfloory * g->img_height) % g->img_height;
		g->buf[y][x] = g->texture[5][g->img_width \
		* g->floortexy + g->floortexx];
		y++;
	}
}

/*
(g->side == 0 && g->raydirx > 0) intersezione
col muro verso destra
(g->side == 0 && g->raydirx < 0) intersezione
col muro verso sinistra
(g->side == 1 && g->raydiry > 0) intersezione
col muro verso sotto
(ultimo caso)intersezione
col muro verso sopra
(distwall) uguale la distanza dei muri

*/
void	floor_casting(t_general *g, int x)
{
	if (g->side == 0 && g->raydirx > 0)
	{
		g->floorxwall = g->mapx;
		g->floorywall = g->mapy + g->wallx;
	}
	else if (g->side == 0 && g->raydirx < 0)
	{
		g->floorxwall = g->mapx;
		g->floorywall = g->mapy - g->wallx;
	}
	else if (g->side == 1 && g->raydiry > 0)
	{
		g->floorxwall = g->mapx + g->wallx;
		g->floorywall = g->mapy;
	}
	else
	{
		g->floorxwall = g->mapx - g->wallx;
		g->floorywall = g->mapy + 1.0;
	}
	g->distwall = g->perpwalldist;
	g->distplayer = 0.0;
	if (g->drawend < 0)
		g->drawend = g->height;
	floor_cont_casting(g, g->drawend + 1, x);
}

/*
ciclo riga per riga lo schermo
in orizzontale
(cellx,celly) posione attuale della cella
(tx,ty) coordinate della texture del pavimento tenendo conto
dell'immagine
(floorx, floory) aggiorno coordinate pavimento
(floortexx, floortexy) texture da usare per il pavimento
(color) colore del pavimento
imposto colore soffittoe pavimento
*/
void	cont_floor_cel_casting(t_general *g, int x, int y)
{
	while (x < g->width)
	{
		g->cellx = (int)(g->floorx);
		g->celly = (int)(g->floory);
		g->tx = (int)(g->img_width * \
		(g->floorx - g->cellx)) & (g->img_width - 1);
		g->ty = (int)(g->img_height * \
		(g->floory - g->celly)) & (g->img_height - 1);
		g->floorx += g->floorstepx;
		g->floory += g->floorstepy;
		g->floortexture = 4;
		g->ceilingtexture = 5;
		g->color = g->texture[g->floortexture][g->img_width * g->ty + g->tx];
		g->buf[y][x] = g->color;
		g->color = g->texture[g->ceilingtexture][g->img_width * g->ty + g->tx];
		g->buf[g->height - 1 - y][x] = g->color;
		x++;
	}
}

/*
ciclo riga per riga lo schermo
in verticale
(g->raydirx0, g->raydiry0)
calcolo direzione del raggio in orizzontale e verticale
(g->p)distanza dal centro dello schermo
(g->posz) piano camera del pavimento soffitto
(g->rowdistance) distanza tra la riga e piano camera
(g->floorstepx, g->floorstepy) incremento pavimento in
orizzontale e verticale
(g->floorx, g->floory) posizione pavimento x,y
*/
void	floor_cel_casting(t_general *g)
{
	int	y;

	y = 0;
	while (y < g->height)
	{
		g->raydirx0 = g->dirx - g->planex;
		g->raydirx1 = g->dirx + g->planex;
		g->raydiry0 = g->diry - g->planey;
		g->raydiry1 = g->diry + g->planey;
		g->p = y - g->height / 2;
		g->posz = 0.5 * g->height;
		g->rowdistance = g->posz / g->p;
		g->floorstepx = g->rowdistance * (g->raydirx1 - g->raydirx0) / g->width;
		g->floorstepy = g->rowdistance * (g->raydiry1 - g->raydiry0) / g->width;
		g->floorx = g->posx + g->rowdistance * g->raydirx0;
		g->floory = g->posy + g->rowdistance * g->raydiry0;
		cont_floor_cel_casting(g, 0, y);
		y++;
	}
}
