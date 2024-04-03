/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:18:21 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/03 17:09:45 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head_cube/cube.h"

void	coordinate_player(t_general *g, int x, int y)
{
	while (g->cubed[y] != 0)
	{
		while (g->cubed[y][x] != 0)
		{
			if (g->cubed[y][x] == 'N' || g->cubed[y][x] == 'S' \
			|| g->cubed[y][x] == 'E' || g->cubed[y][x] == 'W')
			{
				g->x_p = x;
				g->y_p = y;
				g->angle = g->cubed[y][x];
				return ;
			}
			x++;
		}
		x = 0;
		y++;
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
	recopy(g, 0, 0);
	coordinate_player(g, 0, 0);
	draw_map(g, 0, 0);
}
