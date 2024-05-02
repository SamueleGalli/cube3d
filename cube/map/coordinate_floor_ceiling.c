/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_floor_ceiling.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:52:52 by sgalli            #+#    #+#             */
/*   Updated: 2024/05/02 14:27:40 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

char	*floor_ceiling(char *fc, int j, t_general *g)
{
	if (g->l[g->i_fc] == '-' && g->l[g->i_fc + 1] > '0'\
	&& g->l[g->i_fc + 1] <= '9')
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
	if (g->l[g->i_fc] == '-' && g->l[g->i_fc + 1] > '0' && \
	g->l[g->i_fc + 1] <= '9')
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
	while (g->l[g->i_fc] == ' ' && g->l[g->i_fc] != ',')
		g->i_fc++;
}

void	alloc_int(t_general *g, int b)
{
	int	l;
	int	k;

	k = g->i_fc;
	l = 0;
	if (g->l[k] == '-' && g->l[k + 1] > '0' && g->l[k + 1] <= '9')
		k++;
	while (g->l[k] >= '0' && g->l[k] <= '9')
	{
		k++;
		l++;
	}
	allocing_f_s(g, b, l);
	g->j++;
}

void	flooring(t_general *g)
{
	g->i_fc = 0;
	if (g->floor != 0)
	{
		printf("Error\n(too_many floor color)\n");
		end_program(g);
	}
	g->floor = (char **)malloc(sizeof(char *) * 4);
	while (g->l[g->i_fc] != '\0' && g->l[g->i_fc] != '\n' && \
	g->l[g->i_fc] != ',')
	{
		if ((g->l[g->i_fc] >= '0' && g->l[g->i_fc] <= '9') || \
		g->l[g->i_fc] == '-')
			alloc_int(g, 0);
		other_color(g, 2);
		if (g->l[g->i_fc] == 0)
			break ;
		g->i_fc++;
		escape_space(g);
	}
	g->floor[g->j] = NULL;
	g->j = 0;
	g->check_fc++;
}

void	ceiling(t_general *g)
{
	g->i_fc = 0;
	if (g->sky != 0)
	{
		printf("Error\n(too_many ceiling color)\n");
		end_program(g);
	}
	g->sky = (char **)malloc(sizeof(char *) * 4);
	while (g->l[g->i_fc] != '\0' && g->l[g->i_fc] != '\n' && \
	g->l[g->i_fc] != ',')
	{
		if ((g->l[g->i_fc] >= '0' && g->l[g->i_fc] <= '9') || \
		g->l[g->i_fc] == '-')
			alloc_int(g, 1);
		other_color(g, 1);
		if (g->l[g->i_fc] == 0)
			break ;
		g->i_fc++;
		escape_space(g);
	}
	g->sky[g->j] = NULL;
	g->j = 0;
	g->check_fc++;
}
