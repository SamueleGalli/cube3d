/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:11:24 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/18 18:24:17 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

/*
ciclo la texture fino alla fine della schermata
(texy) calcola la coordinata y della texture
(texx) avanza la texture per continuare a disegnarla
(g->color) pixel della texture basata sul tipo di blocco
(pavimento muro)

*/
void	texturing(t_general *g, int x)
{
	int	y;

	y = g->drawstart;
	while (y < g->drawend)
	{
		g->texy = (int)(g->texpos) & (64 - 1);
		g->texpos += g->step;
		printf("%d\n", g->texy);
		g->color = g->texture[g->texnum][g->texy * 64 + g->texx];
		if (g->side == 1)
			g->color = (g->color >> 1) & 8355711;
		g->buf[y][x] = g->color;
		g->rebuf = 1;
		y++;
	}
}
/*
(texnum) indica quale texture verra utilizzata per disengare
la parete
(wallx) indica la distanza del player dal muro
se (side == 0) indica se a colpito una 
parete verticale o orizzontale
(side == 0) orizzontale (side == 1) verticale
queste 2 condizioni
(g->side == 0 && g->raydirx > 0)
(g->side == 1 && g->raydiry < 0)
assicurano che la texture verra disegnata
in modo corretto nella parete
(step) serve a disegnare la parete uniformamente
(g->texx) posizione orizzontale della texture
(tespos) punto di partenza per disegnare la texture
*/

void	painting(t_general *g, int x)
{
	g->texnum = g->cubed[g->mapy][g->mapx];
	if (g->side == 0)
		g->wallx = g->posy + g->perpwalldist * g->raydiry;
	else
		g->wallx = g->posx + g->perpwalldist * g->raydirx;
	g->texx = (int)(g->wallx * (double)64);
	if (g->side == 0 && g->raydirx > 0)
		g->texx = 64 - g->texx - 1;
	if (g->side == 1 && g->raydiry < 0)
		g->texx = 64 - g->texx - 1;
	g->step = 1.0 * 64 / g->lineheight;
	g->texpos = (g->drawstart - g->height / 2 + g->lineheight / 2) * g->step;
	texturing(g, x);
}
