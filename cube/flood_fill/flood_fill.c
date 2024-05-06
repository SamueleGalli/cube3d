/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:38:06 by sgalli            #+#    #+#             */
/*   Updated: 2024/05/06 18:03:00 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	invalid_fill(t_general *g, int j, int i)
{
	if (g->cubed[j + 1][i] != 0 && g->cubed[j + 1][i] == 'F')
	{
		g->filled = 1;
		return ;
	}
	if (j - 1 > 1 && g->cubed[j - 1][i] == 'F')
	{
		g->filled = 1;
		return ;
	}
	if (i - 1 > 1 && (g->cubed[j][i - 1] == 'F' || g->cubed[j][i - 1] == '0'))
	{
		g->filled = 1;
		return ;
	}
	if (g->cubed[j][i + 1] == 0 || g->cubed[j][i + 1] == '0' \
	|| g->cubed[j][i + 1] == 'F')
	{
		g->filled = 1;
		return ;
	}
}

void	filling(t_general *g, int j, int i)
{
	if (g->cubed[j + 1][i] != 0 && g->cubed[j + 1][i] == '0')
	{
		g->cubed[j + 1][i] = '1';
		filling(g, j + 1, i);
	}
	if (j - 1 > 1 && g->cubed[j - 1][i] == '0')
	{
		g->cubed[j - 1][i] = '1';
		filling(g, j - 1, i);
	}
	if (i - 1 > 1 && g->cubed[j][i - 1] == '0')
	{
		g->cubed[j][i - 1] = '1';
		filling(g, j, i - 1);
	}
	if (g->cubed[j][i + 1] != 0 && g->cubed[j][i + 1] == '0')
	{
		g->cubed[j][i + 1] = '1';
		filling(g, j, i + 1);
	}
	else
		invalid_fill(g, j, i);
}

int	check_fill(t_general *g, int i)
{
	int	j2;

	j2 = 1;
	while (g->cubed[j2] != 0 && j2 < g->y_end - 1)
	{
		while (g->cubed[j2][i] != 0)
		{
			if (g->cubed[j2][i] == '0')
			{
				g->cubed[j2][i] = '1';
				filling(g, j2, i);
				if (g->filled == 1)
					return (0);
			}
			i++;
		}
		i = 0;
		j2++;
	}
	return (1);
}

int	flood_fill(t_general *g, int j, int i)
{
	i = 0;
	if (j == 0 || j == g->y_end - 1)
	{
		i = 1;
		while (g->cubed[j][i] != 0)
		{
			if ((i > 0 && i < g->x_end - 1) && \
			(g->cubed[j][i] == '0' || g->cubed[j][i] == 'F'))
			{
				if (check_f(g, j, i) == 0)
					return (0);
			}
			i++;
		}
	}
	else
	{
		if (check_fill(g, i) == 0)
			return (0);
	}
	return (1);
}

int	is_valid(t_general *g)
{
	int	i;
	int	j;

	g->filled = 0;
	j = 0;
	i = 0;
	g->cubed[g->py][g->px] = '0';
	while (g->cubed[j] != 0)
	{
		if (flood_fill(g, j, i) == 0)
			return (0);
		if (g->filled == 1)
			return (0);
		j++;
	}
	return (1);
}
