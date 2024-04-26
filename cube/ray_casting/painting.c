/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:11:24 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/26 12:03:14 by sgalli           ###   ########.fr       */
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
		g->texy = (int)(g->texpos) & (g->img_height - 1);
		g->texpos += g->step;
		if (g->side == 0 && g->mapx >= g->posx)
			g->color = g->texture[0][g->texy * g->img_height + g->texx];
		else if (g->side == 0 && g->mapx < g->posx)
			g->color = g->texture[1][g->texy * g->img_height + g->texx];
		else if (g->side == 1 && g->mapy >= g->posy)
			g->color = g->texture[2][g->texy * g->img_height + g->texx];
		else
			g->color = g->texture[3][g->texy * g->img_height + g->texx];
		g->buf[y][x] = g->color;
		g->rebuf = 1;
		y++;
	}
}
/*
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
	if (g->side == 0)
		g->wallx = g->posy + g->perpwalldist * g->raydiry;
	else
		g->wallx = g->posx + g->perpwalldist * g->raydirx;
	g->wallx -= floor(g->wallx);
	g->texx = (int)(g->wallx * (double)g->img_width);
	if (g->side == 0 && g->raydirx > 0)
		g->texx = g->img_width - g->texx - 1;
	if (g->side == 1 && g->raydiry < 0)
		g->texx = g->img_width - g->texx - 1;
	g->step = 1.0 * g->img_height / g->lineheight;
	g->texpos = (g->drawstart - g->height / 2 + g->lineheight / 2) * g->step;
	texturing(g, x);
}
