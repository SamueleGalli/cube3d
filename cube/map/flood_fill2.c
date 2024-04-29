/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:37:44 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/29 15:21:55 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	shorter_flood_fill(t_general *g, int j, int i)
{
	while (g->cubed[j][i] != '0' && g->cubed[j][i] != '1')
		i++;
	while (g->cubed[j][i] == '1')
		i++;
	while (g->cubed[j][i] != 0)
	{
		g->cubed[j][i] = '1';
		if (g->cubed[j][i + 1] != 0 && g->cubed[j + 1][i] != 0 && \
		j > 0 && j < g->y_end - 1 && i > 0 && i < g->x_end - 1)
			init_check(i, j, g);
		i++;
	}
}

int	flood_fill(t_general *g, int j, int i)
{
	i = 0;
	if (j == 0 || j == g->y_end)
	{
		if (j == g->y_end)
			return (last_check(g, 0, 0));
		while (g->cubed[j][i] != 0)
		{
			if (g->cubed[j][i] == '0' && i > 0 && i < g->x_end - 1)
				return (0);
			i++;
		}
	}
	else
	{
		shorter_flood_fill(g, j, i);
		return (1);
	}
	return (1);
}
