/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:38:06 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/30 15:45:18 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	cont_flood_fill(t_general *g, int i, int j)
{
	if (g->cubed[j][i + 1] != 0 && g->cubed[j][i + 1] == '0' && \
	i + 1 < g->x_end)
	{
		if (g->cubed[j][i + 2] != 0)
			g->cubed[j][i + 1] = '1';
		init_check(i + 1, j, g);
	}
	if (g->cubed[j][i - 1] != 0 && g->cubed[j][i - 1] == '0' && \
	i - 1 > 0)
	{
		if (g->cubed[j][i - 2] != 0)
			g->cubed[j][i - 1] = '1';
		init_check(i - 1, j, g);
	}
}

void	init_check(int i, int j, t_general *g)
{
	if (g->cubed[j + 1][i] != 0 && g->cubed[j + 1][i] == '0' \
	&& j + 1 < g->y_end)
	{
		if (g->cubed[j + 2][i] != 0)
			g->cubed[j + 1][i] = '1';
		init_check(i, j + 1, g);
	}
	if (g->cubed[j - 1][i] != 0 && g->cubed[j - 1][i] == '0' && \
	j - 1 > 0)
	{
		if (g->cubed[j - 2][i] != 0)
			g->cubed[j - 1][i] = '1';
		init_check(i, j - 1, g);
	}
	cont_flood_fill(g, i, j);
}

int	check_angle(int i, int j, t_general *g)
{
	if (j == g->x_end && i == g->y_end && g->cubed[i][j - 1] == '1' && \
	g->cubed[i - 1][i] == '1')
		return (0);
	else if (j == g->x_end && i == 0 && g->cubed[i][j - 1] == '1' && \
	g->cubed[i + 1][i] == '1')
		return (0);
	else if (j == 0 && i == 0 && g->cubed[i][j + 1] == '1' && \
	g->cubed[i + 1][i] == '1')
		return (0);
	else if (j == 0 && i == g->y_end && g->cubed[i][j + 1] == '1' && \
	g->cubed[i - 1][i] == '1')
		return (0);
	return (1);
}

int	last_check(t_general *g, int i, int j)
{
	while (g->cubed[i] != 0 && i < g->y_end)
	{
		while (g->cubed[i][j] != 0)
		{
			if (i > 0 && i < g->y_end && g->cubed[i][j] == '0')
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

	j = 0;
	i = 0;
	while (g->cubed[j] != 0)
	{
		if (flood_fill(g, j, i) == 0)
			return (0);
		j++;
	}
	return (1);
}
