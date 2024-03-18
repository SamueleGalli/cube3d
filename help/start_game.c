/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:18:21 by sgalli            #+#    #+#             */
/*   Updated: 2024/03/18 11:22:02 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	init_game(t_general *g)
{
	int	i;

	g->fd = open(g->v[1], O_RDONLY);
	if (g->fd < 0)
	{
		printf("invalid map.cub try another\n");
		if (g != 0)
			free(g);
		exit(0);
	}
	i = getting_line(g, 0);
	g->fd = open(g->v[1], O_RDONLY);
	alloc_map(g, i);
	if (is_valid(g) == 0)
	{
		printf("map not closed by walls");
		end_program(g);
	}
}
