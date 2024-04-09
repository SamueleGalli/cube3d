/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:18:21 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/09 14:26:48 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head_cube/cube.h"

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
				g->x_p = g->x;
				g->y_p = g->y;
				return ;
			}
			g->x++;
		}
		g->x = 0;
		g->y++;
	}
}

void	set_view(t_general *g)
{
	if (g->p_view == 'N')
	{
		g->x_dir = 0;
		g->y_dir = -1;
	}
	else if (g->p_view == 'S')
	{
		g->x_dir = 0;
		g->y_dir = 1;
	}
	else if (g->p_view == 'E')
	{
		g->x_dir = 1;
		g->y_dir = 0;
	}
	else if (g->p_view == 'W')
	{
		g->x_dir = -1;
		g->y_dir = 0;
	}
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
	set_view(g);
	g->x = 0;
	g->y = 0;
}
