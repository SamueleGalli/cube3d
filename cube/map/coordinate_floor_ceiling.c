/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_floor_ceiling.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:52:52 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/30 15:45:09 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

char	*floor_ceiling(char *fc, int j, t_general *g)
{
	if (g->l[g->i_fc] == '-')
	{
		fc[j++] = '-';
		g->i_fc++;
	}
	while (g->l[g->i_fc] >= '0' && g->l[g->i_fc] <= '9')
		fc[j++] = g->l[g->i_fc++];
	fc[j] = '\0';
	return (fc);
}

void	allocing_f_s(t_general *g, int b, int l)
{
	if (g->l[g->i_fc] == '-')
		l++;
	if (b == 0)
	{
		g->floor[g->j] = (char *)malloc(sizeof(char) * (l + 1));
		g->floor[g->j] = floor_ceiling(g->floor[g->j], 0, g);
	}
	else
	{
		g->sky[g->j] = (char *)malloc(sizeof(char) * (l + 1));
		g->sky[g->j] = floor_ceiling(g->sky[g->j], 0, g);
	}
}

void	alloc_int(t_general *g, int b)
{
	int	l;
	int	k;

	k = g->i_fc;
	l = 0;
	if (g->l[k] == '-')
		k++;
	while (g->l[k] >= '0' && g->l[k] <= '9')
	{
		k++;
		l++;
	}
	printf("l = %d\n", l);
	allocing_f_s(g, b, l);
}

void	flooring(t_general *g)
{
	int	j;

	g->i_fc = 0;
	j = 0;
	g->floor = (char **)malloc(sizeof(char *) * 4);
	while (g->l[g->i_fc] != '\0' && g->l[g->i_fc] != '\n' && \
	g->l[g->i_fc] != ',')
	{
		if ((g->l[g->i_fc] >= '0' && g->l[g->i_fc] <= '9') || \
		g->l[g->i_fc] == '-')
		{
			alloc_int(g, 0);
			printf("g->floor[%d] = %s\n", g->j, g->floor[g->j]);
			g->j++;
		}
		j = 0;
		g->i_fc++;
	}
	g->floor[g->j] = NULL;
	g->j = 0;
}

void	ceiling(t_general *g)
{
	int	j;

	g->i_fc = 0;
	j = 0;
	g->sky = (char **)malloc(sizeof(char *) * 4);
	while (g->l[g->i_fc] != '\0' && g->l[g->i_fc] != '\n' && \
	g->l[g->i_fc] != ',')
	{
		if ((g->l[g->i_fc] >= '0' && g->l[g->i_fc] <= '9') || \
		g->l[g->i_fc] == '-')
		{
			alloc_int(g, 1);
			printf("g->sky[%d] = %s\n", g->j, g->sky[g->j]);
			g->j++;
		}
		j = 0;
		g->i_fc++;
	}
	g->sky[g->j] = NULL;
	g->j = 0;
}
