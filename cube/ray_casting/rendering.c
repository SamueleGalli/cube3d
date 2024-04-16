/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:59:35 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/16 14:16:25 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head_cube/cube.h"

int	update_cube(t_general *g)
{
	int	i;

	i = 0;
	while (i < g->width)
	{
		initialize_ray(g, i);
		checking_ray(g);
		hitting(g);
		distance(g);
		if (g->cubed[g->mapy][g->mapx] == '1')
			g->color = RED;
		if (g->side == 1)
			g->color = g->color / 2;
		verline(g, i);
		i++;
	}
	return (0);
}
