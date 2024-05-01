/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloching.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:58:59 by sgalli            #+#    #+#             */
/*   Updated: 2024/05/01 17:53:51 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	stadardize(t_general *g, int k, int j)
{
	while (k < g->size_mat - 1)
	{
		if (g->cubed[j][k] == ' ' || g->cubed[j][k] == '\n')
			g->tmp[j][k++] = '1';
		else if (g->cubed[j][k] == '\0')
		{
			while (k < g->size_mat - 1)
			{
				g->tmp[j][k] = '1';
				k++;
			}
		}
		else
		{
			g->tmp[j][k] = g->cubed[j][k];
			k++;
		}
	}
	g->tmp[j][k] = '\0';
}

void	realloc_cube_standardize(t_general *g, int max, int j)
{
	int		i;

	free_matrix(g->cubed);
	g->cubed = (char **)malloc(sizeof(char *) * (max + 1));
	while (j < max)
	{
		i = 0;
		g->cubed[j] = (char *)malloc(sizeof(char) * g->size_mat);
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

void	standard_lenght(t_general *g, int max)
{
	int	j;
	int	k;

	j = 0;
	g->tmp = (char **)malloc(sizeof(char *) * (max + 1));
	while (j < max)
	{
		k = 0;
		g->tmp[j] = (char *)malloc(sizeof(char) * (g->size_mat));
		stadardize(g, k, j);
		j++;
	}
	g->tmp[j] = 0;
	realloc_cube_standardize(g, max, 0);
}
