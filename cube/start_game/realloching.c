/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloching.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:58:59 by sgalli            #+#    #+#             */
/*   Updated: 2024/05/03 10:29:11 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	stadardize(t_general *g, int k, int j, int v)
{
	while (k < g->max_len)
	{
		if (g->cubed[j][k] == ' ' || g->cubed[j][k] == '\n')
			g->tmp[j][k++] = '1';
		else if (g->cubed[j][k] == '\0')
		{
			v = k - 1;
			while (k < g->max_len)
				g->tmp[j][k++] = g->cubed[j][v];
		}
		else
		{
			g->tmp[j][k] = g->cubed[j][k];
			k++;
		}
	}
	g->tmp[j][k] = '\0';
}

void	realloc_cube_standardize(t_general *g, int j, int max)
{
	int		i;

	free_matrix(g->cubed);
	g->cubed = (char **)malloc(sizeof(char *) * (max + 1));
	while (j < max)
	{
		i = 0;
		g->cubed[j] = (char *)malloc(sizeof(char) * g->max_len + 1);
		while (g->tmp[j][i] != 0)
		{
			g->cubed[j][i] = g->tmp[j][i];
			i++;
		}
		g->cubed[j][i] = '\0';
		j++;
	}
	g->cubed[j] = 0;
}

void	standard_lenght(t_general *g, int i)
{
	int	j;
	int	k;

	j = 0;
	g->tmp = (char **)malloc(sizeof(char *) * (i + 1));
	while (j < i)
	{
		k = 0;
		g->tmp[j] = (char *)malloc(sizeof(char) * (g->max_len + 1));
		stadardize(g, k, j, 0);
		j++;
	}
	g->tmp[j] = 0;
	realloc_cube_standardize(g, 0, i);
}
