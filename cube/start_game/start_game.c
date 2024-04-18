/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:18:21 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/18 18:24:17 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	coordinate_player(t_general *g)
{
	while (g->cubed[g->y] != 0)
	{
		while (g->cubed[g->y][g->x] != 0)
		{
			if (g->cubed[g->y][g->x] == 'N' || g->cubed[g->y][g->x] == 'S'
				|| g->cubed[g->y][g->x] == 'E' || g->cubed[g->y][g->x] == 'W')
			{
				g->p_view = g->cubed[g->y][g->x];
				g->px = g->x;
				g->py = g->y;
				return ;
			}
			g->x++;
		}
		g->x = 0;
		g->y++;
	}
}

void	continue_angle_view(t_general *g)
{
	if (g->p_view == 'E')
	{
		g->dirx = 1;
		g->diry = 0;
		g->planex = 0;
		g->planey = 0.66;
	}
	else if (g->p_view == 'W')
	{
		g->dirx = -1;
		g->diry = 0;
		g->planex = 0;
		g->planey = -0.66;
	}
}

void	angle_view(t_general *g)
{
	if (g->p_view == 'N')
	{
		g->dirx = 0;
		g->diry = -1;
		g->planex = 0.66;
		g->planey = 0;
	}
	else if (g->p_view == 'S')
	{
		g->dirx = 0;
		g->diry = 1;
		g->planex = -0.66;
		g->planey = 0;
	}
	else
		continue_angle_view(g);
}

void	init_game(t_general *g)
{
	int	i;

	g->fd = open(g->v[1], O_RDONLY);
	if (g->fd < 0)
	{
		printf("Error(invalid map.cub try another)\n");
		if (g != 0)
			free(g);
		exit(0);
	}
	i = getting_line(g, 0);
	g->fd = open(g->v[1], O_RDONLY);
	alloc_map(g, i);
	if (is_valid(g) == 0)
	{
		printf("Error\n(map not closed by walls)");
		end_program(g);
	}
	recopy(g);
	coordinate_player(g);
	angle_view(g);
	g->x = 0;
	g->y = 0;
}
