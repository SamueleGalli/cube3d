/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:30:30 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/08 12:05:30 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head_cube/cube.h"

void	init_check(int i, int j, t_general *g)
{
	if (g->cubed[j + 1][i] != 0 && g->cubed[j + 1][i] == '0')
	{
		g->cubed[j + 1][i] = '1';
		init_check(i, j + 1, g);
	}
	if (g->cubed[j - 1][i] != 0 && g->cubed[j - 1][i] == '0')
	{
		g->cubed[j - 1][i] = '1';
		init_check(i, j - 1, g);
	}
	if (g->cubed[j][i + 1] != 0 && g->cubed[j][i + 1] == '0')
	{
		g->cubed[j][i + 1] = '1';
		init_check(i + 1, j, g);
	}
	if (g->cubed[j][i - 1] != 0 && g->cubed[j][i - 1] == '0')
	{
		g->cubed[j][i - 1] = '1';
		init_check(i - 1, j, g);
	}
}

int	last_check(t_general *g, int i, int j)
{
	while (g->cubed[i] != 0)
	{
		while (g->cubed[i][j] != 0)
		{
			if (g->cubed[i][j] == '0')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	is_valid(t_general *g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	copy_cubed(g);
	while (g->cubed[j] != 0)
	{
		while (g->cubed[j][i] != 0)
		{
			if (g->cubed[j][i] == 'N' || g->cubed[j][i] == 'S'
				|| g->cubed[j][i] == 'W' || g->cubed[j][i] == 'E')
			{
				g->cubed[j][i] = '1';
				init_check(i, j, g);
				return (last_check(g, 0, 0));
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}
