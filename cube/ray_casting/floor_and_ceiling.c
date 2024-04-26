/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_and_ceiling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:22:32 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/26 12:04:18 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

unsigned int	convert_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	floor_cel_casting(t_general *g)
{
	int				y;
	int				x;
	unsigned int	c_color;
	unsigned int	f_color;

	y = 0;
	c_color = convert_color(ft_atoi(g->floor[0]), \
	ft_atoi(g->floor[1]), ft_atoi(g->floor[2]));
	f_color = convert_color(ft_atoi(g->sky[0]), \
	ft_atoi(g->sky[1]), ft_atoi(g->sky[2]));
	while (y < g->height)
	{
		x = 0;
		while (x < g->width)
		{
			g->buf[y][x] = f_color;
			g->buf[g->height - y - 1][x] = c_color;
			x++;
		}
		y++;
	}
}
