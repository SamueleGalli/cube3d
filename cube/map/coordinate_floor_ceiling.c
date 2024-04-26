/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_floor_ceiling.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:52:52 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/26 14:41:06 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	alloc_int(t_general *g, int j, int i, int b)
{
	int	l;
	int	k;

	k = i;
	l = 0;
	while (g->l[k] >= '0' && g->l[k] <= '9')
	{
		k++;
		l++;
	}
	if (b == 0)
	{
		g->floor[g->j] = (char *)malloc(sizeof(char) * (l + 1));
		while (g->l[i] >= '0' && g->l[i] <= '9')
			g->floor[g->j][j++] = g->l[i++];
		g->floor[g->j][j] = '\0';
	}
	else
	{
		g->sky[g->j] = (char *)malloc(sizeof(char) * (l + 1));
		while (g->l[i] >= '0' && g->l[i] <= '9')
			g->sky[g->j][j++] = g->l[i++];
		g->sky[g->j][j] = '\0';
	}
	return (i);
}

void	flooring(t_general *g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	g->floor = (char **)malloc(sizeof(char *) * 4);
	while (g->l[i] != '\0' && g->l[i] != '\n' && g->l[i] != ',')
	{
		if (g->l[i] >= '0' && g->l[i] <= '9')
		{
			i = alloc_int(g, 0, i, 0);
			g->j++;
		}
		j = 0;
		i++;
	}
	g->floor[g->j] = NULL;
	g->j = 0;
}

void	ceiling(t_general *g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	g->sky = (char **)malloc(sizeof(char *) * 4);
	while (g->l[i] != '\0' && g->l[i] != '\n' && g->l[i] != ',')
	{
		if (g->l[i] >= '0' && g->l[i] <= '9')
		{
			i = alloc_int(g, 0, i, 1);
			g->j++;
		}
		j = 0;
		i++;
	}
	g->sky[g->j] = NULL;
	g->j = 0;
}

void	cont_coordinate(t_general *g, int i, int k, int j)
{
	g->coordinate[g->i_coordinate] = (char *)malloc(sizeof(char) * (k + 1));
	while (g->l[i] != '\0' && g->l[i] != '\n')
	{
		g->coordinate[g->i_coordinate][j] = g->l[i];
		i++;
		j++;
	}
	g->coordinate[g->i_coordinate][j] = '\0';
	g->i_coordinate++;
	if (g->i_coordinate == 4)
		g->coordinate[g->i_coordinate] = 0;
}

void	coordinate(t_general *g)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	if (g->coordinate == 0)
		g->coordinate = (char **)malloc(sizeof(char *) * 5);
	while (g->l[i] != '\0' && g->l[i] != '\n' && g->l[i] != '.')
		i++;
	j = i;
	while (g->l[j] != '\0' && g->l[j] != '\n')
	{
		k++;
		j++;
	}
	j = 0;
	cont_coordinate(g, i, k, j);
}