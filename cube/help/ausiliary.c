/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ausiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:36:48 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/02 14:57:23 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head_cube/cube.h"

int	end_mat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i] != 0)
		i++;
	return (i);
}

void	copy_cubed(t_general *g, int i, int j)
{
	g->tmp = (char **)malloc(sizeof(char *) * (end_mat(g->cubed) + 1));
	while (g->cubed[++i] != 0)
	{
		g->tmp[i] = (char *)malloc(sizeof(char ) * \
		(ft_strlen(g->cubed[i]) + 1));
		while (g->cubed[i][j] != 0)
		{
			g->tmp[i][j] = g->cubed[i][j];
			j++;
		}
		g->tmp[i][j] = 0;
		j = 0;
	}
	g->tmp[i] = NULL;
}

void	recopy(t_general *g, int i, int j)
{
	if (g->cubed != 0)
		free_matrix(g->cubed);
	g->cubed = (char **)malloc(sizeof(char *) * (end_mat(g->tmp) + 1));
	while (g->tmp[i] != 0)
	{
		g->cubed[i] = (char *)malloc(sizeof(char ) * \
		(ft_strlen(g->tmp[i] + 1)));
		while (g->tmp[i][j] != 0)
		{
			g->cubed[i][j] = g->tmp[i][j];
			j++;
		}
		g->cubed[i][j] = 0;
		j = 0;
		i++;
	}
	g->cubed[i] = 0;
}
